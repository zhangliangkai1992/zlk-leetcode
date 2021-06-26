/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 15:19
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  int maxSubArray(const std::vector<int>& nums) {
    int res = 0;
    int current = 0;
    for (auto&& n : nums) {
      current += n;
      res = std::max(res, current);
      if (current < 0) {
        current = 0;
      }
    }
    if (res == 0) {
      return *std::max_element(nums.begin(), nums.end());
    }
    return res;
  }
};
TEST(leetcode_53, 1) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(Solution().maxSubArray(nums), 6);
}
