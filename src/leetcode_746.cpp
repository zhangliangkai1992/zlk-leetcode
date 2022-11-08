/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-11-08 08:59
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minCostClimbingStairs(const std::vector<int> &costs) {
    auto res = costs;
    res.push_back(0);
    for (int i = 2; i < res.size(); ++i) {
      res[i] += std::min(res[i - 1], res[i - 2]);
    }
    return res.back();
  }
};

TEST(leetcode, 746) {
  std::vector<int> costs = {10, 15, 20};
  int res = 15;
  ASSERT_EQ(Solution().minCostClimbingStairs(costs), res);
}
