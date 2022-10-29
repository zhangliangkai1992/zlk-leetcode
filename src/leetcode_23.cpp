/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-25 22:17
 */
#include <gtest/gtest.h>

#include <algorithm>
#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *build(std::vector<int> *nums) {
  if (nums == nullptr || nums->empty()) return nullptr;
  auto val = nums->back();
  nums->pop_back();
  return new ListNode(val, build(nums));
}
ListNode *buildFromOrigin(std::vector<int> *nums) {
  std::reverse(nums->begin(), nums->end());
  return build(nums);
}
void FreeNode(ListNode *node) {
  while (node) {
    auto p = node->next;
    delete node;
    node = p;
  }
}

class Solution {
 public:
  ListNode *mergeKLists(std::vector<ListNode *> *allList) {
    auto cmp = [](const ListNode *n1, const ListNode *n2) {
      return n2->val < n1->val;
    };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)>
        queue(cmp);
    for (auto &&node : *allList) {
      if (node != nullptr) queue.push(node);
    }
    auto pivot = new ListNode;
    auto tail = pivot;
    while (!queue.empty()) {
      auto cur = queue.top();
      tail->next = cur;
      tail = cur;
      queue.pop();
      if (cur->next != nullptr) {
        queue.push(cur->next);
      }
    }
    auto res = pivot->next;
    delete pivot;
    return res;
  }
};

TEST(leetcode_23, 1) {
  std::vector<int> nums = {1, 4, 5};
  std::vector<int> expect = {1, 4, 5};
  auto l1 = buildFromOrigin(&nums);
  auto p = l1;
  for (int i = 0; i < expect.size(); ++i, p = p->next) {
    EXPECT_EQ(p->val, expect[i]);
  }
  FreeNode(l1);
}

TEST(leetcode_23, 2) {
  std::vector<std::vector<int>> vecs = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  std::vector<ListNode *> lists;
  for (auto &&v : vecs) {
    lists.push_back(buildFromOrigin(&v));
  }
  std::vector<int> expect = {1, 1, 2, 3, 4, 4, 5, 6};
  auto res = Solution().mergeKLists(&lists);
  auto p = res;
  for (int i = 0; i < expect.size(); ++i, p = p->next) {
    EXPECT_EQ(p->val, expect[i]);
  }
  FreeNode(res);
}
