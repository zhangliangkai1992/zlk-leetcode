/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-10 00:09
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    std::vector<int> height(m, 0);
    std::vector<int> left(m, 0);
    std::vector<int> right(m, m);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int iLeft = 0;
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == '1') {
          ++height[j];
          left[j] = std::max(left[j], iLeft);
        } else {
          height[j] = 0;
          left[j] = 0;
          iLeft = j + 1;
        }
      }
      int iRight = m;
      for (int j = m - 1; j >= 0; --j) {
        if (matrix[i][j] == '1') {
          right[j] = std::min(right[j], iRight);
        } else {
          right[j] = m;
          iRight = j;
        }
        res = std::max(res, (right[j] - left[j]) * height[j]);
      }
    }
    return res;
  }
};

std::vector<std::vector<char>> convert(const std::vector<std::string>& strs) {
  std::vector<std::vector<char>> res;
  for (auto&& str : strs) {
    std::vector<char> cur;
    for (auto&& c : str) {
      cur.push_back(c);
    }
    res.push_back(cur);
  }
  return res;
}
TEST(leetcode85, 1) {
  std::vector<std::string> matrix = {"10100", "10111", "11111", "10010"};
  ASSERT_EQ(Solution().maximalRectangle(convert(matrix)), 6);
}
