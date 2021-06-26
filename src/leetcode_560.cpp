/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-27 00:26
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  int subarraySum(const std::vector<int>& nums, int k) {
    // 计算[0,i]区间和，则sum[i,j] = sum[0,j] - sum[0,i-1]
    std::unordered_map<int, int> sumCount;
    // 前缀和为0的有1个
    ++sumCount[0];
    int res = 0;
    // 当前前缀和
    int current = 0;
    for (auto&& n : nums) {
      current += n;
      res += sumCount[current - k];
      ++sumCount[current];
    }
    return res;
  }
};

TEST(leetcode_560, 1) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(Solution().subarraySum(nums, 2), 2);
}
