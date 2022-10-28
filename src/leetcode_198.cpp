/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-10-28 09:43
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int rob(const std::vector<int> &nums) {
    int notRobLast = 0;
    int robLast = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int nextNotRobLast = std::max(robLast, notRobLast);
      int nextRobLast = notRobLast + nums[i];
      notRobLast = nextNotRobLast;
      robLast = nextRobLast;
    }
    return std::max(notRobLast, robLast);
  }
};

TEST(leetcode, 198) {
  std::vector<int> nums = {1, 2, 3, 1};
  int res = 4;
  ASSERT_EQ(Solution().rob(nums), res);
}
