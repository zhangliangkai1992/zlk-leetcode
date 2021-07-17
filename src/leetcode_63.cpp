/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-10 17:35
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    std::vector<int> res(m, 0);
    res[0] = !grid[0][0];
    for (int j = 1; j < m; ++j) {
      res[j] = res[j - 1] && !grid[0][j];
    }
    for (int i = 1; i < n; ++i) {
      res[0] = res[0] && !grid[i][0];
      for (int j = 1; j < m; ++j) {
        if (grid[i][j]) {
          res[j] = 0;
        } else {
          res[j] += res[j - 1];
        }
      }
    }
    return res[m - 1];
  }
};

TEST(leetcode63, 1) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  ASSERT_EQ(Solution().uniquePathsWithObstacles(grid), 2);
}
