/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-09-27 09:15
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<int> findRightInterval(
      const std::vector<std::vector<int>> &intervals) {
    auto sz = intervals.size();
    std::map<int, int> beginToIndex;
    std::vector<int> res;
    for (int i = 0; i < sz; ++i) {
      beginToIndex[intervals[i][0]] = i;
    }
    for (auto &&interval : intervals) {
      auto it = beginToIndex.lower_bound(interval[1]);
      res.push_back(it == beginToIndex.end() ? -1 : it->second);
    }
    return res;
  }
};

TEST(leetcode, 436) {
  std::vector<std::vector<int>> intervals = {{3, 4}, {2, 3}, {1, 2}};
  std::vector<int> expect = {-1, 0, 1};
  auto res = Solution().findRightInterval(intervals);
  ASSERT_EQ(expect.size(), res.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
