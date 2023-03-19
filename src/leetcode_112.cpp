/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 00:38
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

TEST(leetcode, 112) {
  std::vector<int> preOrder = {5, 4, 11, 7, 2, 8, 13, 4, 1};
  std::vector<int> inOrder = {7, 11, 2, 4, 5, 13, 8, 4, 1};
  auto root = buildTree(preOrder, inOrder);
  int target = 22;
  bool expect = true;
  ASSERT_EQ(expect, Solution().hasPathSum(root, target));
  FreeTree(root);
}
