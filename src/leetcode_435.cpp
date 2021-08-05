/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-04 00:05
 */

#include <gtest/gtest.h>

// 贪心算法
class Solution {
 public:
  int eraseOverlapIntervals(const std::vector<std::vector<int>>& intervals) {
    auto sortInterval = intervals;
    std::sort(sortInterval.begin(), sortInterval.end(),
              [](const std::vector<int>& v1, const std::vector<int>& v2) {
                return v1[1] < v2[1];
              });
    int count = 0;
    int last = 1 << 31;
    for (auto&& v : sortInterval) {
      if (v[0] >= last) {
        last = v[1];
        ++count;
      }
    }
    return intervals.size() - count;
  }
};

TEST(leetcode435, 1) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  ASSERT_EQ(Solution().eraseOverlapIntervals(intervals), 1);
}
