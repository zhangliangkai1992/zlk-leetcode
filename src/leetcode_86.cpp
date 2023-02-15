/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 08:55
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *partition(ListNode *l, int x) {
    auto left = new ListNode;
    auto right = new ListNode;
    auto leftTail = left;
    auto rightTail = right;
    while (l) {
      auto node = new ListNode(l->val);
      if (l->val < x) {
        leftTail->next = node;
        leftTail = node;
      } else {
        rightTail->next = node;
        rightTail = node;
      }
      l = l->next;
    }
    leftTail->next = right->next;
    delete right;
    auto res = left->next;
    delete left;
    return res;
  }
};

TEST(leetcode, 86) {
  std::vector<int> nums = {1, 4, 3, 2, 2, 5};
  decltype(nums) expect = {1, 2, 2, 4, 3, 5};
  auto l = VecToList(nums);
  auto res = Solution().partition(l, 3);
  auto resL = ListToVec(res);
  AssertVector(resL, expect);
  FreeList(res);
  FreeList(l);
}
