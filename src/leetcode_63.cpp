/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 16:30
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int uniquePathsWithObstacles(
      const std::vector<std::vector<int>> &obstaclesGrid) {
    int m = obstaclesGrid.size();
    int n = obstaclesGrid[0].size();
    std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
    res[0][0] = 1;
    for (int i = 0; i < m; ++i) {
      if (obstaclesGrid[i][0] == 1) {
        res[i][0] = 0;
      } else if (i >= 1) {
        res[i][0] = res[i - 1][0];
      }
    }
    for (int j = 0; j < n; ++j) {
      if (obstaclesGrid[0][j] == 1) {
        res[0][j] = 0;
      } else if (j >= 1) {
        res[0][j] = res[0][j - 1];
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstaclesGrid[i][j] == 1) {
          res[i][j] = 0;
        } else {
          res[i][j] = res[i - 1][j] + res[i][j - 1];
        }
      }
    }
    return res[m - 1][n - 1];
  }
};

TEST(leetcode, 63) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int expect = 2;
  ASSERT_EQ(expect, Solution().uniquePathsWithObstacles(grid));
}
