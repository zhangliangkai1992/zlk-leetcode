/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-23 22:20
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n * m;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      auto &&v = matrix[mid / m][mid % m];
      if (v == target) {
        return true;
      } else if (v < target) {
        low = mid + 1;
      } else {
        high = mid;
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
