/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-06 22:56
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int maxProduct(const std::vector<int>& nums) {
    auto sz = nums.size();
    int res = nums[0];
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < sz; ++i) {
      if (nums[i] < 0) {
        std::swap(min, max);
      }
      max = std::max(nums[i], nums[i] * max);
      min = std::min(nums[i], nums[i] * min);
      res = std::max(res, max);
    }
    return res;
  }
};

TEST(leetcode152, 1) {
  std::vector<int> nums = {2, 3, -2, 4};
  ASSERT_EQ(Solution().maxProduct(nums), 6);
}
