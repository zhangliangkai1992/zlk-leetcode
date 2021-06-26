/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 14:32
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  int minimumTotal(const std::vector<std::vector<int>>& triangle) {
    int sz = triangle.size();
    auto res = triangle[0];
    for (int i = 1; i < sz; ++i) {
      res.push_back(*res.rbegin() + *triangle[i].rbegin());
      for (int j = res.size() - 2; j >= 1; --j) {
        res[j] = triangle[i][j] + std::min(res[j], res[j - 1]);
      }
      res[0] = res[0] + triangle[i][0];
    }
    return *std::min_element(res.begin(), res.end());
  }
};
TEST(leetcode_120, 1) {
  std::vector<std::vector<int>> triangle = {
      {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  EXPECT_EQ(Solution().minimumTotal(triangle), 11);
}
TEST(leetcode_120, 2) {
  std::vector<std::vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
  EXPECT_EQ(Solution().minimumTotal(triangle), -1);
}
TEST(leetcode_120, 3) {
  std::vector<std::vector<int>> triangle = {{-1}, {3, 2}, {-3, 1, -1}};
  EXPECT_EQ(Solution().minimumTotal(triangle), -1);
}
