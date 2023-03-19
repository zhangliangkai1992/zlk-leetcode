/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 00:34
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    auto depL = minDepth(root->left);
    auto depR = minDepth(root->right);
    if (depL == 0) {
      return depR + 1;
    }
    if (depR == 0) {
      return depL + 1;
    }
    return std::min(depL, depR) + 1;
  }
};

TEST(leetcode, 111) {
  std::vector<int> preOrder = {3, 9, 20, 15, 7};
  std::vector<int> inOrder = {9, 3, 15, 20, 7};
  auto root = buildTree(preOrder, inOrder);
  auto expect = 2;
  ASSERT_EQ(Solution().minDepth(root), expect);
  FreeTree(root);
}
