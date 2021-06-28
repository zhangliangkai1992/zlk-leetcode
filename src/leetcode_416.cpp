/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-28 22:43
 */
#include <gtest/gtest.h>

#include <numeric>
class Solution {
 public:
  bool canPartition(const std::vector<int>& nums) {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    std::vector<bool> dp(sum / 2 + 1, false);
    dp[0] = true;
    for (auto&& n : nums) {
      for (int i = sum / 2; i >= n; --i) {
        dp[i] = dp[i] || dp[i - n];
      }
    }
    return dp[sum / 2];
  }
};
TEST(leetcode_416, 1) {
  std::vector<int> nums = {1, 2, 3, 5};
  EXPECT_EQ(Solution().canPartition(nums), false);
}
TEST(leetcode_416, 2) {
  std::vector<int> nums = {1, 5, 5, 11};
  EXPECT_EQ(Solution().canPartition(nums), true);
}
TEST(leetcode_416, 3) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(Solution().canPartition(nums), true);
}
