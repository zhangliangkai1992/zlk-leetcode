/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-02 01:10
 */
#include <gtest/gtest.h>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};
ListNode *create(std::vector<int> *nums) {
  if (nums->empty()) return nullptr;
  auto node = new ListNode(nums->back());
  nums->pop_back();
  node->next = create(nums);
  return node;
}
void FreeNode(ListNode *node) {
  auto p = node;
  while (p) {
    auto q = p->next;
    delete p;
    p = q;
  }
}

class Solution {
 public:
  ListNode *CopyList(ListNode *node) {
    if (!node) {
      return nullptr;
    }
    auto p = new ListNode(node->val);
    p->next = CopyList(node->next);
    return p;
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) return CopyList(l2);
    if (l2 == nullptr) return CopyList(l1);
    ListNode *node = nullptr;
    if (l1->val < l2->val) {
      node = new ListNode(l1->val, mergeTwoLists(l1->next, l2));
    } else {
      node = new ListNode(l2->val, mergeTwoLists(l2->next, l1));
    }
    return node;
  }
};

TEST(leetcode_21, 1) {
  std::vector<int> nums = {3, 2, 1};
  auto p = create(&nums);
  FreeNode(p);
}

TEST(leetcode_21, 2) {
  std::vector<int> nums1 = {4, 2, 1};
  auto l1 = create(&nums1);
  std::vector<int> nums2 = {4, 3, 1};
  auto l2 = create(&nums2);

  Solution s;
  auto res = s.mergeTwoLists(l1, l2);
  FreeNode(l1);
  FreeNode(l2);
  FreeNode(res);
}
