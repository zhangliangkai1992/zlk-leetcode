/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-05-25 21:50
 */

#include <gtest/gtest.h>

#include <stack>

class Solution {
  inline int max(int a, int b) { return a > b ? a : b; }
  inline int min(int a, int b) { return a < b ? a : b; }

 public:
  int maxArea(const std::vector<int>& heights) {
    int res = 0;
    int left = 0;
    int right = heights.size() - 1;
    while (left < right) {
        // 最宽开始
      int h = min(heights[left], heights[right]);
      res = max(res, h * (right - left));
      while (heights[left] <= h && left < right) ++left;
      while (heights[right] <= h && left < right) --right;
    }
    return res;
  }
};

TEST(leetcode_11, 1) {
  Solution s;
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(s.maxArea(heights), 49);
}
