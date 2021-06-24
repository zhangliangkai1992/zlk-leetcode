/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-24 23:11
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      const std::vector<std::vector<int>>& all) {
    auto intervals = all;
    if (intervals.empty()) return {};
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& v1, const std::vector<int>& v2) {
                return v1[0] < v2[0];
              });
    int low = intervals[0][0];
    int high = intervals[0][1];
    std::vector<std::vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > high) {
        res.push_back({low, high});
        low = intervals[i][0];
        high = intervals[i][1];
      } else {
        high = std::max(intervals[i][1], high);
      }
    }
    res.push_back({low, high});
    return res;
  }
};
TEST(leetcode_56, 1) {
  std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};
  decltype(intervals) expect = {{1, 5}};
  auto res = Solution().merge(intervals);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i][0], expect[i][0]);
    EXPECT_EQ(res[i][1], expect[i][1]);
  }
}
TEST(leetcode_56, 2) {
  std::vector<std::vector<int>> intervals = {{1, 4}, {0, 4}};
  decltype(intervals) expect = {{0, 4}};
  auto res = Solution().merge(intervals);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i][0], expect[i][0]);
    EXPECT_EQ(res[i][1], expect[i][1]);
  }
}
TEST(leetcode_56, 3) {
  std::vector<std::vector<int>> intervals = {{1, 4}, {2, 3}};
  decltype(intervals) expect = {{1, 4}};
  auto res = Solution().merge(intervals);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i][0], expect[i][0]);
    EXPECT_EQ(res[i][1], expect[i][1]);
  }
}
