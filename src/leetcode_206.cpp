/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 08:43
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *reverseList(ListNode *l) {
    auto header = new ListNode;
    auto p = l;
    while (p) {
      header->next = new ListNode(p->val, header->next);
      p = p->next;
    }
    auto res = header->next;
    delete header;
    return res;
  }
};

TEST(leetcode, 206) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  decltype(nums) expect = {5, 4, 3, 2, 1};
  auto l = VecToList(nums);
  auto rl = Solution().reverseList(l);
  auto rlVec = ListToVec(rl);
  AssertVector(expect, rlVec);
  FreeList(l);
  FreeList(rl);
}
