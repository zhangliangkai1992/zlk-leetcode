/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-21 00:02
 */

#include <include/leetcode_util.h>

class Solution {
  ListNode *reverseList(ListNode *head) {
    auto dummy = new ListNode;
    std::shared_ptr<void> defer(nullptr, [dummy](...) { delete dummy; });
    while (head) {
      auto q = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = q;
    }
    return dummy->next;
  }

 public:
  void reorderList(ListNode *head) {
    auto p = head;
    int len = 0;
    while (p) {
      ++len;
      p = p->next;
    }
    if (len == 0) {
      return;
    }
    p = head;
    auto half = (len + 1) / 2;
    for (int i = 1; i < half; ++i) {
      p = p->next;
    }
    auto right = reverseList(p->next);
    p->next = nullptr;
    p = head;
    while (right) {
      auto q = p->next;
      auto rq = right->next;
      p->next = right;
      right->next = q;
      p = q;
      right = rq;
    }
    return;
  }
};

TEST(leetcode, 143) {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto l = VecToList(vec);
  Solution().reorderList(l);
  auto res = ListToVec(l);
  decltype(res) expect = {1, 5, 2, 4, 3};
  AssertVector(expect, res);
  FreeList(l);
}
