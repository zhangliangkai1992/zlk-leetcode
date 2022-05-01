/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-05-01 11:12
 */

#include <gtest/gtest.h>

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int row = mid / n;
      int col = mid % n;
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};

TEST(leetcode, 74) {
  std::vector<std::vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  ASSERT_TRUE(Solution().searchMatrix(matrix, target));
}
