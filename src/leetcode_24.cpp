/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-20 00:11
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    auto p = head;
    auto q = head->next;
    p->next = swapPairs(q->next);
    q->next = p;
    return q;
  }
};

TEST(leetcode, 24) {
  std::vector<int> vec = {1, 2, 3, 4};
  auto head = VecToList(vec);
  auto r = Solution().swapPairs(head);
  auto res = ListToVec(r);
  decltype(res) expect = {2, 1, 4, 3};
  FreeList(r);
}
