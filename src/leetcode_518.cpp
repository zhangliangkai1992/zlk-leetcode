/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-12 22:57
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int change(int amount, const std::vector<int> &coins) {
    std::vector<int> nums;
    for (auto n : coins) {
      while (n <= amount) {
        nums.push_back(n);
        n = (n << 1);
      }
    }
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto &&n : nums) {
      for (int i = amount; i >= n; --i) {
        dp[i] += dp[i - n];
      }
    }
    return dp[amount];
  }
};

TEST(leetcode, 518) {
  std::vector<int> coins = {1, 2, 5};
  int amount = 5;
  int expect = 4;
  ASSERT_EQ(Solution().change(amount, coins), expect);
}
