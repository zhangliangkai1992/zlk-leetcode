/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 22:33
 */
#include <gtest/gtest.h>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *build(const std::vector<int> &nums) {
  auto dummy = new ListNode;
  for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
    auto node = new ListNode(*it, dummy->next);
    dummy->next = node;
  }
  auto res = dummy->next;
  delete dummy;
  return res;
}
void FreeNode(ListNode *node) {
  while (node) {
    auto p = node->next;
    delete node;
    node = p;
  }
}
class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    auto dummy = new ListNode(0, head);
    auto p = dummy;
    for (int i = 0; i < left - 1; ++i) {
      p = p->next;
    }
    auto cur = p->next;
    for (int i = 0; i < right - left; ++i) {
      auto tmp = p->next;
      p->next = cur->next;
      cur->next = cur->next->next;
      p->next->next = tmp;
    }
    auto res = dummy->next;
    delete dummy;
    return res;
  }
};

TEST(leetcode92, list) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  auto head = build(nums);
  auto p = head;
  for (int i = 0; i < nums.size(); ++i, p = p->next) {
    ASSERT_EQ(nums[i], p->val);
  }
  FreeNode(head);
}

TEST(leetcode92, 1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<int> expect = {1, 4, 3, 2, 5};
  auto head = Solution().reverseBetween(build(nums), 2, 4);
  auto p = head;
  for (int i = 0; i < expect.size(); ++i, p = p->next) {
    ASSERT_EQ(expect[i], p->val);
  }
  FreeNode(head);
}
