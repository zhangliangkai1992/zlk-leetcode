/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-25 00:10
 */
#include <gtest/gtest.h>
class Solution {
  int BinSearch(const std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

 public:
  std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    auto index = BinSearch(nums, target);
    if (index == -1) return {-1, -1};
    int low = index;
    while (low >= 0 && nums[low] == target) --low;
    int high = index;
    while (high < nums.size() && nums[high] == target) ++high;
    return {low + 1, high - 1};
  }
};
TEST(leetcode_34, 1) {
  Solution s;
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  std::vector<int> expect = {3, 4};
  auto res = s.searchRange(nums, 8);
  EXPECT_EQ(res[0], expect[0]);
  EXPECT_EQ(res[1], expect[1]);
}
TEST(leetcode_34, 2) {
  Solution s;
  std::vector<int> nums = {1};
  std::vector<int> expect = {0, 0};
  auto res = s.searchRange(nums, 1);
  EXPECT_EQ(res[0], expect[0]);
  EXPECT_EQ(res[1], expect[1]);
}
