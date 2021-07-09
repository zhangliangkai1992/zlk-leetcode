/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-09 23:31
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int majorityElement(const std::vector<int>& nums) {
    int res = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (res == nums[i]) {
        ++count;
      } else {
        --count;
        if (count < 0) {
          res = nums[i];
          count = 1;
        }
      }
    }
    return res;
  }
};

TEST(leetcode169, 1) {
  std::vector<int> nums = {3, 2, 3};
  ASSERT_EQ(Solution().majorityElement(nums), 3);
}
