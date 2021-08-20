/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-20 08:48
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int getMaximumConsecutive(const std::vector<int>& coins) {
    auto sortedCoins = coins;
    std::sort(sortedCoins.begin(), sortedCoins.end());
    int res = 1;
    for (auto&& n : sortedCoins) {
      if (n > res) return res;
      res += n;
    }
    return res;
  }
};

TEST(leetcode1798, 1) {
  std::vector<int> coins = {1, 4, 10, 3, 1};
  int expect = 20;
  ASSERT_EQ(Solution().getMaximumConsecutive(coins), expect);
}
