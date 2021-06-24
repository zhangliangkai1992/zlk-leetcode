/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-24 23:32
 */
#include <gtest/gtest.h>

#include <queue>

class Solution {
  // dfs with memory
  int dfs(std::vector<std::vector<std::vector<int>>>* pRes, int m, int n,
          int move, int row, int col) {
    if (row < 0 || row >= m || col < 0 || col >= n) {
      return 1;
    }
    if (move == 0) return 0;
    auto& res = *pRes;
    int& count = res[row][col][move];
    if (count != -1) return count;
    constexpr int x[] = {1, 0, -1, 0};
    constexpr int y[] = {0, -1, 0, 1};
    constexpr int MOD = 1e9 + 7;
    count = 0;
    for (int i = 0; i < 4; ++i) {
      count = (count + dfs(pRes, m, n, move - 1, row + x[i], col + y[i])) % MOD;
    }
    return count;
  }

 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
    std::vector<std::vector<std::vector<int>>> res(
        m, std::vector<std::vector<int>>(n, std::vector<int>(maxMove + 1, -1)));
    return dfs(&res, m, n, maxMove, startRow, startCol);
  }
};
TEST(leetcode_576, 1) {
  Solution s;
  EXPECT_EQ(s.findPaths(2, 2, 2, 0, 0), 6);
}
