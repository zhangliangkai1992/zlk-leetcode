/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-05 23:13
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

void FreeList(ListNode *node) {
  while (node) {
    auto p = node->next;
    delete node;
    node = p;
  }
}
class Solution {
  ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }
    if (l1->val < l2->val) {
      l1->next = merge(l1->next, l2);
      return l1;
    }
    l2->next = merge(l1, l2->next);
    return l2;
  }

 public:
  // 归并排序
  ListNode *sortList(ListNode *head) {
    if (!head || head->next == nullptr) return head;
    auto dummy = new ListNode(0, head);
    auto p = dummy;
    auto q = head;
    while (q) {
      p = p->next;
      q = q->next;
      if (q) {
        q = q->next;
      }
    }
    auto half = p->next;
    p->next = nullptr;
    auto l1 = sortList(head);
    auto l2 = sortList(half);
    delete dummy;
    return merge(l1, l2);
  }
};

TEST(leetcode148, 1) {
  std::vector<int> nums = {4, 2, 1, 3};
  std::vector<int> expect = {1, 2, 3, 4};
  auto res = Solution().sortList(build(nums));
  auto p = res;
  for (int i = 0; i < expect.size(); ++i, p = p->next) {
    ASSERT_EQ(p->val, expect[i]);
  }
  FreeList(res);
}
