/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-05 10:30
 */

#ifndef INCLUDE_LEETCODE_UTIL_H_
#define INCLUDE_LEETCODE_UTIL_H_
#include <gtest/gtest.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>
template <typename T>
void AssertVector(const std::vector<T> &n1, const std::vector<T> &n2) {
  ASSERT_EQ(n1.size(), n2.size());
  for (int i = 0; i < n1.size(); ++i) {
    ASSERT_EQ(n1[i], n2[i]);
  }
}

template <typename T>
void AssertMatrix(const std::vector<std::vector<T>> &m1,
                  const std::vector<std::vector<T>> &m2) {
  ASSERT_EQ(m1.size(), m2.size());
  for (int i = 0; i < m1.size(); ++i) {
    AssertVector(m1[i], m2[i]);
  }
}

template <typename T>
void AssertSubVectorEqual(const std::vector<T> &v1, int sz,
                          const std::vector<T> &v2) {
  ASSERT_LE(sz, v2.size());
  for (int i = 0; i < sz; ++i) {
    ASSERT_EQ(v1[i], v2[i]);
  }
}

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int v = 0, ListNode *n = nullptr) : val(v), next(n) {}
};

ListNode *VecToList(const std::vector<int> &nums) {
  auto header = new ListNode;
  auto tail = header;
  for (auto &&n : nums) {
    auto node = new ListNode(n);
    tail->next = node;
    tail = node;
  }
  auto res = header->next;
  delete header;
  return res;
}

std::vector<int> ListToVec(const ListNode *l) {
  std::vector<int> list;
  while (l) {
    list.push_back(l->val);
    l = l->next;
  }
  return list;
}

void FreeList(ListNode *l) {
  while (l) {
    auto next = l->next;
    delete l;
    l = next;
  }
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int val = 0, TreeNode *left = nullptr,
                    TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

void FreeTree(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  FreeTree(root->left);
  FreeTree(root->right);
  delete root;
}

TreeNode *buildTree(const std::vector<int> &preOrder,
                    const std::vector<int> &inOrder) {
  if (preOrder.empty()) {
    return nullptr;
  }
  auto len = preOrder.size();
  auto root = new TreeNode(preOrder[0]);
  int index = 0;
  while (index < len) {
    if (preOrder[0] == inOrder[index]) {
      break;
    }
    ++index;
  }
  auto leftLen = index;
  auto leftPreOrder =
      std::vector<int>(preOrder.begin() + 1, preOrder.begin() + 1 + leftLen);
  auto leftInOrder =
      std::vector<int>(inOrder.begin(), inOrder.begin() + leftLen);
  root->left = buildTree(leftPreOrder, leftInOrder);
  auto rightLen = len - 1 - leftLen;
  auto rightPreOrder =
      std::vector<int>(preOrder.begin() + 1 + leftLen, preOrder.end());
  auto rightInOrder =
      std::vector<int>(inOrder.begin() + index + 1, inOrder.end());
  root->right = buildTree(rightPreOrder, rightInOrder);
  return root;
}

void checkSameTree(TreeNode *r1, TreeNode *r2) {
  if (r1 == r2) {
    return;
  }
  if (r1 && !r2 || !r1 && r2) {
    ASSERT_TRUE(false);
  }
  ASSERT_EQ(r1->val, r2->val);
  checkSameTree(r1->left, r2->left);
  checkSameTree(r1->right, r2->right);
}
#endif // INCLUDE_LEETCODE_UTIL_H_
