/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 01:37
 */
#include <include/leetcode_util.h>

class Solution {
  int64_t calc(const std::vector<int64_t> &digs) {
    int64_t base = 1;
    decltype(base) res = 0;
    for (auto it = digs.rbegin(); it != digs.rend(); ++it) {
      res += base * *it;
      base *= 10;
    }
    return res;
  }
  void dfs(TreeNode *root, std::vector<int64_t> *path, int64_t *sum) {
    if (root == nullptr) {
      return;
    }
    path->push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      *sum += calc(*path);
      path->pop_back();
      return;
    }
    dfs(root->left, path, sum);
    dfs(root->right, path, sum);
    path->pop_back();
  }

 public:
  int sumNumbers(TreeNode *root) {
    int64_t sum = 0;
    std::vector<int64_t> path;
    dfs(root, &path, &sum);
    return sum;
  }
};

TEST(leetcode, 129) {
  std::vector<int> preOrder = {4, 9, 5, 1, 0};
  std::vector<int> inOrder = {5, 9, 1, 4, 0};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().sumNumbers(root);
  decltype(res) expect = 1026;
  ASSERT_EQ(res, expect);
  FreeTree(root);
}
