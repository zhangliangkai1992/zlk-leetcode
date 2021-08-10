/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-10 23:41
 */

#include <gtest/gtest.h>

class Solution {
  int robber(const std::vector<int>& nums, int low, int high) {
    int prev = 0;
    int current = 0;
    for (int i = low; i <= high; ++i) {
      int next = std::max(prev + nums[i], current);
      prev = current;
      current = next;
    }
    return current;
  }

 public:
  int rob(const std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1) return nums.back();
    return std::max(robber(nums, 0, sz - 2), robber(nums, 1, sz - 1));
  }
};

TEST(leetcode213, 1) {
  std::vector<int> nums = {1, 2, 3, 1};
  int expect = 4;
  ASSERT_EQ(Solution().rob(nums), expect);
}
