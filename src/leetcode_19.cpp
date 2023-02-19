/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-19 23:33
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int len = 0;
    auto p = head;
    while (p) {
      ++len;
      p = p->next;
    }
    auto dummy = new ListNode(0, head);
    int step = len - n;
    p = dummy;
    while (step) {
      --step;
      p = p->next;
    }
    auto d = p->next;
    p->next = d->next;
    delete d;
    auto r = dummy->next;
    delete dummy;
    return r;
  }
};

TEST(leetcode, 19) {
  std::vector<int> list = {1, 2, 3, 4, 5};
  auto head = VecToList(list);
  auto res = Solution().removeNthFromEnd(head, 2);
  auto resVec = ListToVec(res);
  decltype(resVec) expect = {1, 2, 3, 5};
  AssertVector(resVec, expect);
  FreeList(res);
}
