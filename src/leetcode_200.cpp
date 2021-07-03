/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 11:27
 */
#include <gtest/gtest.h>

#include <queue>

class Solution {
  void bfs(const std::vector<std::vector<char>>& grid, int x, int y,
           std::vector<std::vector<bool>>* access) {
    auto n = grid.size();
    auto m = grid[0].size();
    if (x >= n || x < 0 || y >= m || y < 0 || (*access)[x][y] ||
        grid[x][y] == '0')
      return;
    (*access)[x][y] = true;
    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) {
      bfs(grid, x + dirX[i], y + dirY[i], access);
    }
  }

 public:
  int numIslands(const std::vector<std::vector<char>>& grid) {
    auto n = grid.size();
    auto m = grid[0].size();
    std::vector<std::vector<bool>> accessed(n, std::vector<bool>(m, false));
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!accessed[i][j] && grid[i][j] == '1') {
          bfs(grid, i, j, &accessed);
          ++res;
        }
      }
    }
    return res;
  }
};

std::vector<std::vector<char>> trans(const std::vector<std::string>& input) {
  std::vector<std::vector<char>> res;
  for (auto&& s : input) {
    std::vector<char> out;
    for (auto&& c : s) {
      out.push_back(c);
    }
    res.push_back(out);
  }
  return res;
}
TEST(leetcode200, 1) {
  std::vector<std::string> grid = {"11110", "11010", "11000", "00000"};
  ASSERT_EQ(Solution().numIslands(trans(grid)), 1);
}
