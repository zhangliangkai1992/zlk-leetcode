/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-29 22:43
 */
#include <gtest/gtest.h>

#include <stack>
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x = 0, TreeNode* left = nullptr,
                    TreeNode* right = nullptr)
      : val(x), left(left), right(right) {}
};
std::vector<int> TreePreOrder(TreeNode* root) {
  if (root == nullptr) return {};
  std::vector<int> res;
  res.push_back(root->val);
  auto left = TreePreOrder(root->left);
  res.insert(res.end(), left.begin(), left.end());
  auto right = TreePreOrder(root->right);
  res.insert(res.end(), right.begin(), right.end());
  return res;
}
std::vector<int> TreeInOrder(TreeNode* root) {
  if (root == nullptr) return {};
  std::vector<int> res;
  auto left = TreeInOrder(root->left);
  res.insert(res.end(), left.begin(), left.end());
  res.push_back(root->val);
  auto right = TreeInOrder(root->right);
  res.insert(res.end(), right.begin(), right.end());
  return res;
}

TreeNode* build(const std::vector<int>& preorder, int plow, int phigh,
                const std::vector<int>& inorder, int ilow, int ihigh) {
  if (plow > phigh) return nullptr;
  auto value = preorder[plow];
  auto root = new TreeNode(value);
  int i = ilow;
  for (; i <= ihigh; ++i) {
    if (inorder[i] == value) break;
  }
  int leftSz = i - ilow;
  root->left = build(preorder, plow + 1, plow + leftSz, inorder, ilow, i - 1);
  root->right =
      build(preorder, plow + leftSz + 1, phigh, inorder, i + 1, ihigh);
  return root;
}

TreeNode* buildTree(const std::vector<int>& preorder,
                    const std::vector<int>& inorder) {
  int sz = preorder.size();
  return build(preorder, 0, sz - 1, inorder, 0, sz - 1);
}
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    std::vector<int> res;
    auto p = root;
    while (p != nullptr || !st.empty()) {
      if (p != nullptr) {
        st.push(p);
        p = p->left;
      } else {
        auto top = st.top();
        st.pop();
        res.push_back(top->val);
        p = top->right;
      }
    }
    return res;
  }
};
// 前序遍历
std::vector<int> preorderTree(TreeNode* root) {
  auto p = root;
  std::stack<TreeNode*> st;
  std::vector<int> res;
  while (p != nullptr || !st.empty()) {
    if (p != nullptr) {
      st.push(p);
      res.push_back(p->val);
      p = p->left;
    } else {
      auto top = st.top();
      st.pop();
      p = top->right;
    }
  }
  return res;
}

// 后序遍历=反转前序遍历（父 右 左)
std::vector<int> postOrderTree(TreeNode* root) {
  auto p = root;
  std::stack<TreeNode*> st;
  std::vector<int> res;
  while (p != nullptr || !st.empty()) {
    if (p != nullptr) {
      st.push(p);
      // 插入首位
      res.insert(res.begin(), p->val);
      p = p->right;
    } else {
      auto top = st.top();
      st.pop();
      p = top->left;
    }
  }
  return res;
}
TEST(leetcode94, 1) {
  std::vector<int> preorder = {1, 2, 3};
  std::vector<int> inorder = {1, 3, 2};
  auto root = buildTree(preorder, inorder);
  auto res = Solution().inorderTraversal(root);
  ASSERT_EQ(res.size(), inorder.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], inorder[i]);
  }
  auto pre = preorderTree(root);
  ASSERT_EQ(pre.size(), preorder.size());
  for (int i = 0; i < pre.size(); ++i) {
    ASSERT_EQ(pre[i], preorder[i]);
  }
  std::vector<int> postOrder = {3, 2, 1};
  auto post = postOrderTree(root);
  ASSERT_EQ(post.size(), postOrder.size());
  for (int i = 0; i < post.size(); ++i) {
    ASSERT_EQ(post[i], postOrder[i]);
  }
}
