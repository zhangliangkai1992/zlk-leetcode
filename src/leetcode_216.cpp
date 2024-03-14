/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024-03-13 09:25
 */

#include <gtest/gtest.h>

class Solution {
 public:
  void Dfs(int k, int n, std::vector<int> *current, int sum,
           std::vector<std::vector<int>> *res) {
    if (current->size() == k) {
      if (n == sum) {
        res->push_back(*current);
      }
      return;
    }
    auto last = current->empty() ? 1 : current->back() + 1;
    for (int i = last; i <= 9; ++i) {
      if (sum + i > n) {
        break;
      }
      current->emplace_back(i);
      Dfs(k, n, current, sum + i, res);
      current->pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<int> current;
    int current_sum = 0;
    std::vector<std::vector<int>> res;
    Dfs(k, n, &current, current_sum, &res);
    return res;
  }
};

TEST(leetcode, 216) {
  int k = 9;
  int n = 45;
  std::vector<std::vector<int>> expect = {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
  auto res = Solution().combinationSum3(k, n);
  EXPECT_EQ(res.size(), expect.size());
}
