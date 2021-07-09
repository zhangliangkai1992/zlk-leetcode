/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-06 23:26
 */
#include <gtest/gtest.h>

class Solution {
  int findK(std::vector<int>* pNums, int low, int high, int k) {
    auto& nums = *pNums;
    int pivot = nums[low];
    auto left = low;
    auto right = high;
    while (left < right) {
      while (left < right && nums[right] >= pivot) --right;
      while (left < right && nums[left] <= pivot) ++left;
      std::swap(nums[left], nums[right]);
    }
    std::swap(nums[left], nums[low]);
    int sz = high - left + 1;
    if (sz == k) return nums[left];
    if (sz < k) {
      return findK(pNums, low, left - 1, k - sz);
    }
    return findK(pNums, left + 1, high, k);
  }

 public:
  int findKthLargest(const std::vector<int>& vec, int k) {
    auto nums = vec;
    return findK(&nums, 0, nums.size() - 1, k);
  }
};

TEST(leetcode215, 1) {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  ASSERT_EQ(Solution().findKthLargest(nums, 2), 5);
}
TEST(leetcode215, 2) {
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  ASSERT_EQ(Solution().findKthLargest(nums, 4), 4);
}
TEST(leetcode215, 3) {
  std::vector<int> nums = {2, 1};
  ASSERT_EQ(Solution().findKthLargest(nums, 2), 1);
}
