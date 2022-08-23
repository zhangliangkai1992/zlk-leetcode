/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-08-22 09:57
 */

#include <gtest/gtest.h>

class Solution {
 public:
  bool search(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == target) {
        return true;
      }
      // [low,mid)有序
      if (nums[low] < nums[mid]) {
        if (nums[low] <= target && target < nums[mid]) {
          high = mid;
        } else {
          low = mid + 1;
        }
      } else if (nums[low] > nums[mid]) {
        if (nums[mid] < target && target <= nums[high - 1]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      } else {
        ++low;
      }
    }
    return false;
  }
};

TEST(leetcode, 81) {
  std::vector<int> nums = {4, 5, 6, 6, 7, 0, 1, 2, 4, 4};
  ASSERT_TRUE(Solution().search(nums, 0));
  ASSERT_TRUE(Solution().search(nums, 1));
  ASSERT_TRUE(Solution().search(nums, 2));
  std::vector<int> n2 = {3, 1};
  ASSERT_FALSE(Solution().search(n2, 2));
}