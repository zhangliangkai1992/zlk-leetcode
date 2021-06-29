/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-29 22:00
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto&& n : coins) {
        if (i >= n && dp[i - n] != -1) {
          if (dp[i] == -1) {
            dp[i] = dp[i - n] + 1;
          } else {
            dp[i] = std::min(dp[i], dp[i - n] + 1);
          }
        }
      }
    }
    return dp[amount];
  }
};

TEST(leetcode322, 1) {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  int expect = 3;
  ASSERT_EQ(Solution().coinChange(coins, amount), expect);
}
TEST(leetcode322, 2) {
  std::vector<int> coins = {2};
  int amount = 3;
  int expect = -1;
  ASSERT_EQ(Solution().coinChange(coins, amount), expect);
}
TEST(leetcode322, 3) {
  std::vector<int> coins = {1};
  int amount = 0;
  int expect = 0;
  ASSERT_EQ(Solution().coinChange(coins, amount), expect);
}
