/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-23 22:12
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int RecursiveGet(std::vector<std::vector<int>>* costs, int i, int j) {
    if (j <= i) {
      return 0;
    }
    auto& cur = *costs;
    if (cur[i][j] != -1) {
      return cur[i][j];
    }
    int cost = ~(1 << 31);
    for (int k = i; k <= j; ++k) {
      cost = std::min(cost, k + std::max(RecursiveGet(costs, i, k - 1),
                                         RecursiveGet(costs, k + 1, j)));
    }
    cur[i][j] = cost;
    return cur[i][j];
  }

  int getMoneyAmount(int n) {
    // cost[i,j] = k表示在范围[i,j]所需要的最小金币
    // 状态转移方程cost[i,j] = min{k+max(cost[i,k-1],cost[k+1,j], k belongs
    std::vector<std::vector<int>> costs(n + 1, std::vector<int>(n + 1, -1));
    return RecursiveGet(&costs, 1, n);
  }
};
TEST(leetcode_375, 1) {
  Solution s;
  EXPECT_EQ(s.getMoneyAmount(10), 16);
}
