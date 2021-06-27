/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-27 00:45
 */
#include <gtest/gtest.h>

#include <numeric>

class Solution {
 public:
  // 问题转变成nums数组中取正号和P和取负号和N的差为target
  // P+N=sum(nums) P-N=target
  // 0-1背包问题：若干个元素和为P
  int findTargetSumWays(const std::vector<int>& nums, int target) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum < target || (sum + target) & 1) return 0;
    auto p = (sum + target) >> 1;
    std::vector<int> dp(p + 1, 0);
    dp[0] = 1;
    for (auto&& n : nums) {
      for (int i = p; i >= n; --i) {
        dp[i] += dp[i - n];
      }
    }
    return dp[p];
  }
};

TEST(leetcode_494, 1) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  EXPECT_EQ(Solution().findTargetSumWays(nums, 3), 5);
}
