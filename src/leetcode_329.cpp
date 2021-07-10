/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-10 16:44
 */
#include <gtest/gtest.h>

class Solution {
  inline bool outBound(int i, int j, int n, int m) {
    return i >= n || i < 0 || j >= m || j < 0;
  }
  int dfs(const std::vector<std::vector<int>>& matrix, int i, int j,
          std::vector<std::vector<int>>* pCache) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (outBound(i, j, n, m)) return 0;
    auto& cache = *pCache;
    if (cache[i][j]) return cache[i][j];
    int res = 1;
    int dirX[] = {1, 0, -1, 0};
    int dirY[] = {0, 1, 0, -1};
    for (int k = 0; k < 4; ++k) {
      auto nextX = i + dirX[k];
      auto nextY = j + dirY[k];
      if (outBound(nextX, nextY, n, m) || matrix[nextX][nextY] <= matrix[i][j])
        continue;
      res = std::max(res, 1 + dfs(matrix, nextX, nextY, pCache));
    }
    cache[i][j] = res;
    return res;
  }

 public:
  int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> cache(n, std::vector<int>(m, 0));
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res = std::max(res, dfs(matrix, i, j, &cache));
      }
    }
    return res;
  }
};

TEST(leetcode329, 1) {
  std::vector<std::vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  ASSERT_EQ(Solution().longestIncreasingPath(matrix), 4);
}
