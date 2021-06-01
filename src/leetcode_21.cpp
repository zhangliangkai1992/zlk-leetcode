/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-02 01:10
 */
#include <gtest/gtest.h>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};
ListNode* create(std::vector<int>* nums) {
  if (nums->empty()) return nullptr;
  auto node = new ListNode(nums->back());
  nums->pop_back();
  node->next = create(nums);
  return node;
}
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
};

TEST(leetcode_21, 1) {
  std::vector<int> nums = {3, 2, 1};
  auto p = create(&nums);
  EXPECT_EQ(p->val, 1);
  p = p->next;
  EXPECT_EQ(p->val, 2);
  p = p->next;
  EXPECT_EQ(p->val, 3);
}

TEST(leetcode_21, 2) {
  std::vector<int> nums1 = {4, 2, 1};
  auto l1 = create(&nums1);
  std::vector<int> nums2 = {4, 3, 1};
  auto l2 = create(&nums2);

  Solution s;
  auto res = s.mergeTwoLists(l1, l2);
  auto p = res;
  EXPECT_EQ(p->val, 1);
  p = p->next;
  EXPECT_EQ(p->val, 1);
  p = p->next;
  EXPECT_EQ(p->val, 2);
  p = p->next;
  EXPECT_EQ(p->val, 3);
  p = p->next;
  EXPECT_EQ(p->val, 4);
  p = p->next;
  EXPECT_EQ(p->val, 4);
  p = p->next;
}
