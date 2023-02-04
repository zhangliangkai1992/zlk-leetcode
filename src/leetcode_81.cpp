/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-04 20:52
 */

#include <gtest/gtest.h>

class Solution {
public:
  bool search(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      auto mid = (high - low) / 2 + low;
      if (nums[mid] == target) {
        return true;
      }
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
  std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  bool expect = true;
  ASSERT_EQ(Solution().search(nums, target), expect);
}