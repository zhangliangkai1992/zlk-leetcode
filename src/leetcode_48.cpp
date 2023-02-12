/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 08:55
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>> *pMatrix) {
    auto &&matrix = *pMatrix;
    auto m = matrix.size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; i + j < m; ++j) {
        std::swap(matrix[i][j], matrix[m - 1 - j][m - 1 - i]);
      }
    }
    std::reverse(matrix.begin(), matrix.end());
  }
};

TEST(leetcode, 48) {
  std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
  decltype(matrix) expect = {{3, 1}, {4, 2}};
  Solution().rotate(&matrix);
  AssertMatrix(matrix, expect);
}
