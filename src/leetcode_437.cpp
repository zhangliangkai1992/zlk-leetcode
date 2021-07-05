/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-05 23:52
 */
#include <gtest/gtest.h>

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
  void dfs(TreeNode* root, std::vector<int>* path, int target, int* res) {
    path->push_back(root->val);
    if (root->left) {
      dfs(root->left, path, target, res);
    }
    if (root->right) {
      dfs(root->right, path, target, res);
    }
    int sum = 0;
    for (auto it = path->rbegin(); it != path->rend(); ++it) {
      sum += *it;
      if (sum == target) ++*res;
    }
    path->pop_back();
  }

 public:
  int pathSum(TreeNode* root, int target) {
    if (!root) {
      return 0;
    }
    std::vector<int> path;
    int res = 0;
    dfs(root, &path, target, &res);
    return res;
  }
};

TEST(leetcode437, 1) {
  std::vector<int> preorder = {10, 5, 3, 3, -2, 2, 1, -3, 11};
  std::vector<int> inorder = {3, 3, -2, 5, 2, 1, 10, -3, 11};
  auto root = buildTree(preorder, inorder);
  ASSERT_EQ(Solution().pathSum(root, 8), 3);
}
