/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-17 00:54
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *l) {
    auto p = l ? l->next : nullptr;
    while (p && l->val == p->val) {
      l->next = p->next;
      delete p;
      p = l->next;
    }
    if (p) {
      deleteDuplicates(p);
    }
    return l;
  }
};

TEST(leetcode, 83) {
  std::vector<int> nums = {1, 1, 2};
  decltype(nums) expect = {1, 2};
  auto l = VecToList(nums);
  auto r = Solution().deleteDuplicates(l);
  auto res = ListToVec(r);
  FreeList(l);
  AssertVector(expect, res);
}
