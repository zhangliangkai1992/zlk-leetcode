/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 01:16
 */

#include <include/leetcode_util.h>

class Solution {
  int dfs(TreeNode *root, int *res) {
    if (root == nullptr) {
      return 0;
    }
    int sumL = dfs(root->left, res);
    int sumR = dfs(root->right, res);
    int sum = std::max(std::max(sumL, sumR) + root->val, root->val);
    *res = std::max(*res, sum);
    *res = std::max(*res, sumL + sumR + root->val);
    return sum;
  }

 public:
  int maxPathSum(TreeNode *root) {
    int res = 1 << 31;
    dfs(root, &res);
    return res;
  }
};

TEST(leetcode, 124) {
  std::vector<int> preOrder = {-10, 9, 20, 15, 7};
  std::vector<int> inOrder = {9, -10, 15, 20, 7};
  auto root = buildTree(preOrder, inOrder);
  int expect = 42;
  ASSERT_EQ(Solution().maxPathSum(root), expect);
  FreeTree(root);
}
