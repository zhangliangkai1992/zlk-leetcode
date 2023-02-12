/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 09:49
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>> *pMatrix) {
    auto &&matrix = *pMatrix;
    std::unordered_set<int> zeroRow;
    std::unordered_set<int> zeroCol;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          zeroRow.insert(i);
          zeroCol.insert(j);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (zeroRow.find(i) != zeroRow.end() ||
            zeroCol.find(j) != zeroCol.end()) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

TEST(leetcode, 73) {
  std::vector<std::vector<int>> matrix = {
      {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  decltype(matrix) expect = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  Solution().setZeroes(&matrix);
  AssertMatrix(matrix, expect);
}
