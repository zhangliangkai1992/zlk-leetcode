/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-17 01:37
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *rotateRight(ListNode *l, int k) {
    if (k == 0 || !l) {
      return l;
    }
    int len = 0;
    auto p = l;
    ListNode *tail = nullptr;
    while (p) {
      tail = p;
      ++len;
      p = p->next;
    }
    k = k % len;
    if (tail) {
      tail->next = l;
    }
    int rotate = len - k;
    p = tail;
    while (rotate) {
      --rotate;
      p = p->next;
    }
    auto res = p->next;
    p->next = nullptr;
    return res;
  }
};

TEST(leetcode, 61) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = 2;
  auto l = VecToList(nums);
  auto r = Solution().rotateRight(l, k);
  auto res = ListToVec(r);
  decltype(res) expect = {4, 5, 1, 2, 3};
  FreeList(r);
}
