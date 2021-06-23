/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-23 23:35
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int minPathSum(const std::vector<std::vector<int>>& grid) {
    auto res = grid;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 1; i < n; ++i) {
      res[i][0] = res[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < m; ++j) {
      res[0][j] = res[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        res[i][j] = grid[i][j] + std::min(res[i - 1][j], res[i][j - 1]);
      }
    }
    return *res.rbegin()->rbegin();
  }
};

TEST(leetcode_64, 1) {
  Solution s;
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  EXPECT_EQ(s.minPathSum(grid), 7);
}
