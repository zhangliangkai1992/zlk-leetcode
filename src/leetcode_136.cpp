/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-25 22:06
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int singleNumber(const std::vector<int>& nums) {
    int res = 0;
    for (auto&& n : nums) {
      res = res ^ n;
    }
    return res;
  }
};

TEST(leetcode_136, 1) {
  std::vector<int> nums = {2, 2, 1};
  EXPECT_EQ(Solution().singleNumber(nums), 1);
}
