/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 08:20
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto header = new ListNode;
    auto tail = header;
    while (l1 || l2) {
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      int sum = n1 + n2 + carry;
      tail->next = new ListNode(sum % 10);
      carry = sum / 10;
      tail = tail->next;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry) {
      tail->next = new ListNode(carry);
    }
    auto res = header->next;
    delete header;
    return res;
  }
};

TEST(leetcode, 2) {
  std::vector<int> v1 = {2, 4, 3};
  std::vector<int> v2 = {5, 6, 4};
  auto l1 = VecToList(v1);
  auto l2 = VecToList(v2);
  auto l = Solution().addTwoNumbers(l1, l2);
  auto res = ListToVec(l);
  std::vector<int> expect = {7, 0, 8};
  AssertVector(expect, res);
  FreeList(l1);
  FreeList(l2);
  FreeList(l);
}
