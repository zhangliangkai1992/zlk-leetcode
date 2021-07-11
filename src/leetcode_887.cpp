/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-11 19:06
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int superEggDrop(int k, int n) {
    if (k > n) k = n;
    // dp[i][j] = f表示操作i次j个鸡蛋能检验的最大高度为f
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
    int i = 0;
    while (dp[i][k] < n) {
      ++i;
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
      }
    }
    return i;
  }
};

TEST(leetcode887, 1) {
  ASSERT_EQ(Solution().superEggDrop(1, 2), 2);
  ASSERT_EQ(Solution().superEggDrop(2, 6), 3);
  ASSERT_EQ(Solution().superEggDrop(3, 14), 4);
}
