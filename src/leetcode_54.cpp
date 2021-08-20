/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-20 08:17
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    if (!m) return {};
    int n = matrix[0].size();
    std::vector<std::vector<bool>> found(m, std::vector<bool>(n, false));
    const int dir_x[] = {0, 1, 0, -1};
    const int dir_y[] = {1, 0, -1, 0};
    // 初始方向
    int dir = 0;
    int x = 0;
    int y = -1;
    std::vector<int> res;
    res.reserve(m * n);
    for (int i = 0; i < m * n; ++i) {
      int next_x = x + dir_x[dir];
      int next_y = y + dir_y[dir];
      if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n ||
          found[next_x][next_y]) {
        dir = (dir + 1) % 4;
      }
      x += dir_x[dir];
      y += dir_y[dir];
      res.push_back(matrix[x][y]);
      found[x][y] = true;
    }
    return res;
  }
};

TEST(leetcode54, 1) {
  std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = Solution().spiralOrder(mat);
  decltype(res) expect = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
