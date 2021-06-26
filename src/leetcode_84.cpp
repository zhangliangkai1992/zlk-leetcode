/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 16:07
 */
#include <gtest/gtest.h>
class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    auto sz = heights.size();
    // left[i]表示在i的左边第一个小于heights[i]的索引
    std::vector<int> left(sz, -1);
    for (int i = 1; i < sz; ++i) {
      auto p = i - 1;
      while (p >= 0 && heights[i] <= heights[p]) {
        p = left[p];
      }
      left[i] = p;
    }
    // right[i]表示在i的右边第一个小于heights[i]的索引
    std::vector<int> right(sz, sz);
    for (int j = sz - 2; j >= 0; --j) {
      auto p = j + 1;
      while (p < sz && heights[j] <= heights[p]) {
        p = right[p];
      }
      right[j] = p;
    }
    int area = 0;
    for (int i = 0; i < sz; ++i) {
      area = std::max(area, heights[i] * (right[i] - left[i] - 1));
    }
    return area;
  }
};
TEST(leetcode_84, 1) {
  std::vector<int> heights = {2, 1, 5, 6, 2, 3};
  EXPECT_EQ(Solution().largestRectangleArea(heights), 10);
}
