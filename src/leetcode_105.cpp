/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 18:26
 */
#include <gtest/gtest.h>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x = 0, TreeNode *left = nullptr,
                    TreeNode *right = nullptr)
      : val(x), left(left), right(right) {}
};
std::vector<int> TreePreOrder(TreeNode *root) {
  if (root == nullptr) return {};
  std::vector<int> res;
  res.push_back(root->val);
  auto left = TreePreOrder(root->left);
  res.insert(res.end(), left.begin(), left.end());
  auto right = TreePreOrder(root->right);
  res.insert(res.end(), right.begin(), right.end());
  return res;
}
std::vector<int> TreeInOrder(TreeNode *root) {
  if (root == nullptr) return {};
  std::vector<int> res;
  auto left = TreeInOrder(root->left);
  res.insert(res.end(), left.begin(), left.end());
  res.push_back(root->val);
  auto right = TreeInOrder(root->right);
  res.insert(res.end(), right.begin(), right.end());
  return res;
}

void FreeTree(TreeNode *root) {
  if (root) {
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
  }
}
class Solution {
  TreeNode *build(const std::vector<int> &preorder, int plow, int phigh,
                  const std::vector<int> &inorder, int ilow, int ihigh) {
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

 public:
  TreeNode *buildTree(const std::vector<int> &preorder,
                      const std::vector<int> &inorder) {
    int sz = preorder.size();
    return build(preorder, 0, sz - 1, inorder, 0, sz - 1);
  }
};

TEST(leetcode_105, 1) {
  std::vector<int> preorder = {3, 9, 20, 15, 7};
  std::vector<int> inorder = {9, 3, 15, 20, 7};
  auto t = Solution().buildTree(preorder, inorder);
  auto expect_pre = TreePreOrder(t);
  EXPECT_EQ(preorder.size(), expect_pre.size());
  for (int i = 0; i < preorder.size(); ++i) {
    EXPECT_EQ(preorder[i], expect_pre[i]);
  }
  auto expect_in = TreeInOrder(t);
  EXPECT_EQ(inorder.size(), expect_in.size());
  for (int i = 0; i < inorder.size(); ++i) {
    EXPECT_EQ(inorder[i], expect_in[i]);
  }
  FreeTree(t);
}
