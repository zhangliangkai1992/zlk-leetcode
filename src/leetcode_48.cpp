/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-13 23:31
 */
#include <gtest/gtest.h>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>* mat) {
    auto& matrix = *mat;
    int n = matrix.size();
    int low = 0;
    int high = n - 1;
    while (low < high) {
      std::swap(matrix[low++], matrix[high--]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

TEST(leetcode_48, 1) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  s.rotate(&matrix);
  decltype(matrix) expect = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  EXPECT_EQ(matrix.size(), expect.size());
  for (int i = 0; i < matrix.size(); ++i) {
    EXPECT_EQ(matrix[i].size(), expect[i].size());
    for (int j = 0; j < matrix[i].size(); ++j) {
      EXPECT_EQ(matrix[i][j], expect[i][j]);
    }
  }
}
