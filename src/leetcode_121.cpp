/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 23:48
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    const int MAX = ~(1 << 31);
    int res = 0;
    int cur = MAX;
    for (auto&& n : prices) {
      cur = std::min(cur, n);
      res = std::max(n - cur, res);
    }
    return res;
  }
};

TEST(leetcode121, 1) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(Solution().maxProfit(prices), 5);
}
