/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-29 22:21
 */
#include <gtest/gtest.h>

class Solution {
 public:
  // 快慢指针，因为取值范围在索引范围之内，且可能出现2次或以上
  int findDuplicate(const std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[slow];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

TEST(leetcode287, 1) {
  std::vector<int> nums = {1, 3, 4, 2, 2};
  int except = 2;
  ASSERT_EQ(Solution().findDuplicate(nums), except);
}
