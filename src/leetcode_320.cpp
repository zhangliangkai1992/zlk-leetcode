/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-10-13 09:13
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int coinChange(const std::vector<int> &coins, int amount) {
    const int kMax = ~(1 << 31);
    std::vector<int> dp(amount + 1, kMax);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto &&n : coins) {
        if (i >= n && dp[i - n] != kMax) {
          dp[i] = std::min(dp[i], dp[i - n] + 1);
        }
      }
    }
    return dp[amount] == kMax ? -1 : dp[amount];
  }
};

TEST(leetcode, 320) {
  std::vector<int> coins = {2};
  int amount = 3;
  int res = -1;
  ASSERT_EQ(Solution().coinChange(coins, amount), res);
}
