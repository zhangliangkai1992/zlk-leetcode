/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-01-31 23:46
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int search(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low != high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == target) {
        return mid;
      }
      // 左半边有序
      if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && target < nums[mid]) {
          high = mid;
        } else {
          low = mid + 1;
        }
      } else {
        // 右半边有序
        if (nums[mid] < target && target <= nums[high - 1]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
    }
    return -1;
  }
};

TEST(leetcode, 33) {
  std::vector<int> nums = {5, 1, 3};
  ASSERT_EQ(Solution().search(nums, 3), 2);
}
