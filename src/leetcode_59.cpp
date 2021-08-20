/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-20 08:31
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    const int dir_x[] = {0, 1, 0, -1};
    const int dir_y[] = {1, 0, -1, 0};
    // 初始方向
    int dir = 0;
    int x = 0;
    int y = -1;
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    for (int i = 0; i < n * n; ++i) {
      int next_x = x + dir_x[dir];
      int next_y = y + dir_y[dir];
      if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n ||
          res[next_x][next_y]) {
        dir = (dir + 1) % 4;
      }
      x += dir_x[dir];
      y += dir_y[dir];
      res[x][y] = i + 1;
    }
    return res;
  }
};

TEST(leetcode59, 1) {
  int n = 2;
  auto res = Solution().generateMatrix(n);
  decltype(res) expect = {{1, 2}, {4, 3}};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
}
