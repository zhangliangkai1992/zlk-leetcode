/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-05-24 22:56
 */

#include <gtest/gtest.h>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *CopyList(ListNode *src) {
    if (src == nullptr) {
      return nullptr;
    }
    auto node = new ListNode(src->val);
    node->next = CopyList(src->next);
    return node;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) return CopyList(l2);
    if (l2 == nullptr) return CopyList(l1);
    int carry = 0;
    auto p1 = l1;
    auto p2 = l2;
    auto result = new ListNode();
    ListNode *tail = result;
    while (p1 != nullptr || p2 != nullptr) {
      int n1 = 0;
      if (p1 != nullptr) {
        n1 = p1->val;
        p1 = p1->next;
      }
      int n2 = 0;
      if (p2 != nullptr) {
        n2 = p2->val;
        p2 = p2->next;
      }
      auto sum = n1 + n2 + carry;

      auto node = new ListNode(sum % 10);
      tail->next = node;
      tail = node;
      carry = sum / 10;
    }
    if (carry) {
      auto node = new ListNode(carry);
      tail->next = node;
    }
    auto res = result->next;
    delete result;
    return res;
  }
};

ListNode *BuildNode(int n) {
  auto node = new ListNode;
  auto tail = node;
  while (n) {
    tail->val = n % 10;
    n /= 10;
    if (n) {
      tail->next = new ListNode;
      tail = tail->next;
    }
  }
  return node;
}

void FreeNode(ListNode *node) {
  auto p = node;
  while (p) {
    auto q = p->next;
    delete p;
    p = q;
  }
}

TEST(leetcode_2, build) {
  auto p = BuildNode(1234);
  FreeNode(p);
}

TEST(leetcode_2, 1) {
  auto l1 = BuildNode(1234);
  auto l2 = BuildNode(9999);
  Solution s;
  auto p = s.addTwoNumbers(l1, l2);
  FreeNode(l1);
  FreeNode(l2);
  FreeNode(p);
}
