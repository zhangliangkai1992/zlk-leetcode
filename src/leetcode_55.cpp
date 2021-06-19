/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 02:03
 */
#include <gtest/gtest.h>

class Solution {
 public:
  bool canJump(const std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 0) return true;
    int current = 0;
    int cur_max = nums[0];
    if (cur_max >= sz - 1) return true;
    while (true) {
      int next_max = cur_max;
      for (int i = current + 1; i <= cur_max; ++i) {
        if (i + nums[i] >= sz - 1) return true;
        next_max = std::max(next_max, i + nums[i]);
      }
      if (next_max == cur_max) {
        break;
      }
      current = cur_max;
      cur_max = next_max;
    }
    return false;
  }
};

TEST(leetcode_55, 1) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_EQ(Solution().canJump(nums), true);
}
