/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-08 16:15
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int numberOfArithmeticSlices(const std::vector<int>& nums) {
    int res = 0;
    int sz = nums.size();
    // 长度为s的等差数列，新增末尾则新增len=s-2个子数列
    int len = 0;
    for (int i = 2; i < sz; ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        res += ++len;
      } else {
        len = 0;
      }
    }
    return res;
  }
};

TEST(leetcode413, 1) {
  std::vector<int> nums = {1};
  int expect = 0;
  ASSERT_EQ(Solution().numberOfArithmeticSlices(nums), expect);
}
