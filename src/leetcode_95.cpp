/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-19 23:32
 */
#include <include/leetcode_util.h>

class Solution {
  TreeNode *cloneTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    auto newRoot = new TreeNode(root->val);
    newRoot->left = cloneTree(root->left);
    newRoot->right = cloneTree(root->right);
    return newRoot;
  }
  void destroyTree(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
  }
  std::vector<TreeNode *> dfs(int low, int high) {
    std::vector<TreeNode *> res;
    for (int i = low; i < high; ++i) {
      auto leftTrees = dfs(low, i);
      auto rightTrees = dfs(i + 1, high);
      if (leftTrees.empty() && rightTrees.empty()) {
        res.push_back(new TreeNode(i));
      } else if (leftTrees.empty()) {
        for (auto t : rightTrees) {
          auto root = new TreeNode(i);
          root->right = t;
          res.push_back(root);
        }
      } else if (rightTrees.empty()) {
        for (auto t : leftTrees) {
          auto root = new TreeNode(i);
          root->left = t;
          res.push_back(root);
        }
      } else {
        for (auto lt : leftTrees) {
          for (auto rt : rightTrees) {
            auto root = new TreeNode(i);
            root->left = cloneTree(lt);
            root->right = cloneTree(rt);
            res.push_back(root);
          }
        }
        for (auto lt : leftTrees) {
          destroyTree(lt);
        }
        for (auto rt : rightTrees) {
          destroyTree(rt);
        }
      }
    }
    return res;
  }

 public:
  std::vector<TreeNode *> generateTrees(int n) { return dfs(1, n + 1); }
};

TEST(leetcode, 95) {
  int n = 3;
  auto res = Solution().generateTrees(n);
  for (auto r : res) {
    FreeTree(r);
  }
  ASSERT_TRUE(true);
}
