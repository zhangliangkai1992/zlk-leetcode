/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-14 00:55
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res = {root->val};
    auto left = preorderTraversal(root->left);
    for (auto &&v : left) {
      res.push_back(v);
    }
    auto right = preorderTraversal(root->right);
    for (auto &&v : right) {
      res.push_back(v);
    }
    return res;
  }
};

TEST(leetcode, 144) {
  std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().preorderTraversal(root);
  AssertVector(preOrder, res);
  FreeTree(root);
}