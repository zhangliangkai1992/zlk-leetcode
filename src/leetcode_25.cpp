/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-20 00:19
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) {
      return head;
    }
    auto dummy = new ListNode(0, head);
    std::shared_ptr<void> defer(nullptr, [dummy](...) { delete dummy; });
    auto p = dummy;
    for (int i = 0; i < k; ++i) {
      if (p) {
        p = p->next;
      } else {
        return head;
      }
    }
    if (!p) {
      return head;
    }
    auto newDummy = new ListNode(0, reverseKGroup(p->next, k));
    p->next = nullptr;
    std::shared_ptr<void> defer2(nullptr, [newDummy](...) { delete newDummy; });
    while (dummy->next) {
      auto q = dummy->next;
      dummy->next = q->next;
      q->next = newDummy->next;
      newDummy->next = q;
    }
    return newDummy->next;
  }
};

TEST(leetcode, 25) {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto h = VecToList(vec);
  auto r = Solution().reverseKGroup(h, 3);
  auto res = ListToVec(r);
  decltype(res) expect = {3, 2, 1, 4, 5};
  AssertVector(expect, res);
  FreeList(r);
}
