/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-17 01:03
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *l) {
    if (!l) {
      return l;
    }
    auto p = l->next;
    auto shouldDel = p && p->val == l->val;
    if (!shouldDel) {
      l->next = deleteDuplicates(l->next);
      return l;
    }
    while (p && p->val == l->val) {
      l->next = p->next;
      delete p;
      p = l->next;
    }
    auto h = l->next;
    delete l;
    return deleteDuplicates(h);
  }
};

TEST(leetcode, 82) {
  std::vector<int> nums = {1, 2, 3, 3, 4, 4, 5};
  decltype(nums) expect = {1, 2, 5};
  auto l = VecToList(nums);
  auto r = Solution().deleteDuplicates(l);
  auto res = ListToVec(r);
  FreeList(r);
  AssertVector(expect, res);
}
