/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-23 23:45
 */
#include <gtest/gtest.h>

class Solution {
  int SearchStart(const std::vector<int>& nums, int low, int high) {
    while (low < high) {
      int mid = (low + high) / 2;
      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }

 public:
  int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int sz = nums.size();
    int right = sz - 1;
    auto index = SearchStart(nums, left, right);
    while (left <= right) {
      int mid = (left + right) / 2;
      auto real_pos = (mid + index) % sz;
      auto n = nums[real_pos];
      if (n == target) return real_pos;
      if (n > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
TEST(leetcode_33, 1) {
  Solution s;
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(s.search(nums, 3), -1);
  EXPECT_EQ(s.search(nums, 0), 4);
  nums = {1, 3};
  EXPECT_EQ(s.search(nums, 0), -1);
}
