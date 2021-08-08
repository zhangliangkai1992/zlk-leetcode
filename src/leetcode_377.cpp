/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-08 23:36
 */

#include <gtest/gtest.h>

class Solution {
  std::unordered_map<int, int> cache_;

 public:
  int combinationSum4(const std::vector<int>& nums, int target) {
    if (cache_.count(target)) {
      return cache_[target];
    }
    int count = 0;
    for (auto&& n : nums) {
      if (n < target) {
        count += combinationSum4(nums, target - n);
      } else if (n == target) {
        ++count;
      }
    }
    return cache_[target] = count;
  }
};

TEST(leetcode377, 1) {
  std::vector<int> nums = {1, 2, 3};
  int target = 4;
  int expect = 7;
  ASSERT_EQ(Solution().combinationSum4(nums, target), expect);
}
