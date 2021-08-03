/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-03 23:49
 */

#include <gtest/gtest.h>

#include <numeric>

class Solution {
 public:
  int maxRotateFunction(const std::vector<int>& nums) {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    auto sz = nums.size();
    // 求f0
    int f = 0;
    for (int i = 0; i < sz; ++i) {
      f += i * nums[i];
    }
    int res = f;
    // f[i] = f[i-1] + sum - sz * nums[sz - i];
    for (auto i = sz - 1; i > 0; --i) {
      f = f + sum - sz * nums[i];
      res = std::max(f, res);
    }
    return res;
  }
};

TEST(leetcode396, 1) {
  std::vector<int> nums = {4, 3, 2, 6};
  int expect = 26;
  ASSERT_EQ(Solution().maxRotateFunction(nums), expect);
}
