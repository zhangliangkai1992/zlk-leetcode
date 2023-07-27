/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 00:06
 */

#include <include/leetcode_util.h>

class Solution {
  bool valid(TreeNode *root, int64_t low, int64_t high) {
    if (!root) {
      return true;
    }
    if (low < root->val && root->val < high) {
      return valid(root->left, low, root->val) &&
             valid(root->right, root->val, high);
    }
    return false;
  }

 public:
  bool isValidBST(TreeNode *root) {
    const int kBits = 63;
    const int64_t kMin = 1L << kBits;
    const int64_t kMax = ~kMin;
    return valid(root, kMin, kMax);
  }
};

TEST(leetcode, 98) {
  std::vector<int> preOrder = {5, 1, 4, 3, 6};
  std::vector<int> inOrder = {1, 5, 3, 4, 6};
  auto root = buildTree(preOrder, inOrder);
  ASSERT_EQ(Solution().isValidBST(root), false);
  FreeTree(root);
}
