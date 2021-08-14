/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-14 21:12
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int cherryPickup(const std::vector<std::vector<int>>& grid) {
    int N = grid.size();
    int M = 2 * N - 1;
    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
    // 在第n步中，dp[i][p] = k:
    // j = n - i, q = n - p
    // [0,0]=>[i,j]=>[p,q]=>[0,0]
    // 该路径最多可以采取k个草莓
    dp[0][0] = grid[0][0];
    for (int n = 1; n < M; ++n) {
      for (int i = N - 1; i >= 0; --i) {
        for (int p = N - 1; p >= 0; --p) {
          int j = n - i;
          int q = n - p;
          if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 ||
              grid[p][q] < 0) {
            dp[i][p] = -1;
            continue;
          }
          if (i > 0) dp[i][p] = std::max(dp[i][p], dp[i - 1][p]);
          if (p > 0) dp[i][p] = std::max(dp[i][p], dp[i][p - 1]);
          if (i > 0 && p > 0) dp[i][p] = std::max(dp[i][p], dp[i - 1][p - 1]);
          if (dp[i][p] >= 0) {
            dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
          }
        }
      }
    }
    return std::max(dp[N - 1][N - 1], 0);
  }
};

TEST(leetcode741, 1) {
  std::vector<std::vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
  int expect = 5;
  ASSERT_EQ(Solution().cherryPickup(grid), expect);
}

TEST(leetcode741, 2) {
  std::vector<std::vector<int>> grid = {{1, 1, -1}, {1, -1, -1}, {-1, 1, 1}};
  int expect = 0;
  ASSERT_EQ(Solution().cherryPickup(grid), expect);
}
