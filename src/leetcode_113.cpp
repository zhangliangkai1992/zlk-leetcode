/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-14 23:44
 */

#include <gtest/gtest.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x = 0, TreeNode *left = nullptr,
                    TreeNode *right = nullptr)
      : val(x), left(left), right(right) {}
};
TreeNode *build(const std::vector<int> &preorder, int plow, int phigh,
                const std::vector<int> &inorder, int ilow, int ihigh) {
  if (plow > phigh) return nullptr;
  auto value = preorder[plow];
  auto root = new TreeNode(value);
  int i = ilow;
  for (; i <= ihigh; ++i) {
    if (inorder[i] == value) break;
  }
  int leftSz = i - ilow;
  root->left = build(preorder, plow + 1, plow + leftSz, inorder, ilow, i - 1);
  root->right =
      build(preorder, plow + leftSz + 1, phigh, inorder, i + 1, ihigh);
  return root;
}

TreeNode *buildTree(const std::vector<int> &preorder,
                    const std::vector<int> &inorder) {
  int sz = preorder.size();
  return build(preorder, 0, sz - 1, inorder, 0, sz - 1);
}

void FreeTree(TreeNode *root) {
  if (root) {
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
  }
}

class Solution {
  void dfs(TreeNode *root, int target, std::vector<std::vector<int>> *res,
           std::vector<int> *path) {
    if (root == nullptr) {
      return;
    }
    path->push_back(root->val);
    target -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
      if (target == 0) {
        res->push_back(*path);
      }
      path->pop_back();
      return;
    }
    if (root->left) {
      dfs(root->left, target, res, path);
    }
    if (root->right) {
      dfs(root->right, target, res, path);
    }
    path->pop_back();
  }

 public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    dfs(root, target, &res, &path);
    return res;
  }
};

TEST(leetcode113, 1) {
  std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
  std::vector<int> in = {7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
  auto root = buildTree(pre, in);
  int target = 22;
  auto res = Solution().pathSum(root, target);
  decltype(res) expect = {{5, 4, 11, 2}, {5, 8, 4, 5}};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
  FreeTree(root);
}
