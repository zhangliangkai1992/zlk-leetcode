/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 23:26
 */

#include <include/leetcode_util.h>
#include <queue>

class Solution {
 public:
  ListNode *mergeKLists(const std::vector<ListNode *> &lists) {
    auto head = new ListNode;
    auto cmp = [](ListNode *n1, ListNode *n2) { return n1->val > n2->val; };
    std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> que(
        cmp);
    for (auto &&l : lists) {
      if (l) {
        que.push(l);
      }
    }
    auto tail = head;
    while (!que.empty()) {
      auto top = que.top();
      que.pop();
      tail->next = top;
      if (top->next) {
        que.push(top->next);
      }
      tail = top;
    }
    auto res = head->next;
    delete head;
    return res;
  }
};

TEST(leetcode, 23) {
  std::vector<std::vector<int>> listsVec = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  std::vector<ListNode *> lists;
  for (auto &&v : listsVec) {
    lists.push_back(VecToList(v));
  }
  auto res = Solution().mergeKLists(lists);
  auto resVec = ListToVec(res);
  decltype(resVec) expect = {1, 1, 2, 3, 4, 4, 5, 6};
  AssertVector(resVec, expect);
  FreeList(res);
}
