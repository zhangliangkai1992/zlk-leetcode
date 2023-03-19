/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 00:48
 */

#include <include/leetcode_util.h>

class Solution {
  void dfs(std::vector<int> *path, std::vector<std::vector<int>> *res,
           TreeNode *root, const int target) {
    if (root == nullptr) {
      return;
    }
    path->push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      if (root->val == target) {
        res->push_back(*path);
      }
      path->pop_back();
      return;
    }
    dfs(path, res, root->left, target - root->val);
    dfs(path, res, root->right, target - root->val);
    path->pop_back();
  }

 public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    dfs(&path, &res, root, targetSum);
    return res;
  }
};

TEST(leetcode, 113) {
  std::vector<int> preOrder = {5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
  std::vector<int> inOrder = {7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
  auto root = buildTree(preOrder, inOrder);
  int target = 22;
  auto res = Solution().pathSum(root, target);
  decltype(res) expect = {{5, 4, 11, 2}, {5, 8, 4, 5}};
  AssertMatrix(res, expect);
  FreeTree(root);
}
