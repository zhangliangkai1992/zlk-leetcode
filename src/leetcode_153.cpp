/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-07 19:55
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int findMin(const std::vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
      if (nums[low] < nums[high]) break;
      int mid = (low + high) / 2;
      if (nums[mid] >= nums[low]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

TEST(leetcode153, 1) {
  std::vector<int> nums = {3, 4, 5, 1, 2};
  int expect = 1;
  ASSERT_EQ(Solution().findMin(nums), expect);
}
