/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-19 22:29
 */

#include <include/leetcode_util.h>

class Solution {
  TreeNode *build(TreeNode *root) {
    if (root == nullptr || root->left == nullptr && root->right == nullptr) {
      return root;
    }
    auto leftTail = build(root->left);
    auto rightTail = build(root->right);
    if (leftTail) {
      leftTail->right = root->right;
      leftTail->left = nullptr;
      root->right = root->left;
      root->left = nullptr;
    }
    if (!rightTail) {
      rightTail = leftTail;
    }
    return rightTail;
  }

 public:
  void flatten(TreeNode *root) { build(root); }
};

TEST(leetcode, 114) {
  std::vector<int> preOrder = {1, 2, 3};
  std::vector<int> inOrder = {3, 2, 1};
  auto root = buildTree(preOrder, inOrder);
  Solution().flatten(root);
  std::vector<int> preOrderExpect = preOrder;
  auto expect = buildTree(preOrderExpect, preOrderExpect);
  checkSameTree(root, expect);
  FreeTree(expect);
  FreeTree(root);
}

