/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-18 23:26
 */

#include <include/leetcode_util.h>
#include <queue>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::queue<TreeNode *> que;
    std::vector<std::vector<int>> res;
    if (root) {
      que.push(root);
    }
    while (!que.empty()) {
      auto sz = que.size();
      std::vector<int> level;
      for (int i = 0; i < sz; ++i) {
        auto node = que.front();
        que.pop();
        level.push_back(node->val);
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};

TEST(leetcode, 144) {
  std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().levelOrder(root);
  decltype(res) expect = {{1}, {2, 3}, {4, 5, 6, 7}};
  AssertMatrix(expect, res);
  FreeTree(root);
}
