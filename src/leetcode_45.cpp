/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-23 23:19
 */
#include <gtest/gtest.h>
class Solution {
 public:
  int jump(const std::vector<int>& nums) {
    auto sz = nums.size();
    constexpr int MAX = ~(1 << 31);
    std::vector<int> steps(sz, MAX);
    steps[0] = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz && j <= i + nums[i]; ++j) {
        steps[j] = std::min(steps[j], steps[i] + 1);
      }
    }
    return steps[sz - 1];
  }
};

TEST(leetcode_45, 1) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  Solution s;
  EXPECT_EQ(s.jump(nums), 2);
}
