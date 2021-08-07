/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-07 19:05
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minAbsDifference(const std::vector<int>& nums, int goal) {
    if (goal == 0) return 0;
    int neg = 0;
    int pos = 0;
    for (auto&& n : nums) {
      pos += std::max(0, n);
      neg += std::min(0, n);
    }
    if (goal < neg || goal > pos) {
      return std::min(std::abs(goal - pos), std::abs(goal - neg));
    }
    std::set<int> leftSum = {0};
    auto sz = nums.size();
    int res = std::abs(goal);
    for (int i = 0; i < sz / 2; ++i) {
      auto current = leftSum;
      for (auto&& n : current) {
        if (nums[i] + n == goal) return 0;
        // insert happens
        if (leftSum.insert(n + nums[i]).second) {
          res = std::min(res, std::abs(n + nums[i] - goal));
        }
      }
    }
    std::set<int> rightSum = {0};
    for (int i = sz / 2; i < sz; ++i) {
      auto current = rightSum;
      for (auto&& n : current) {
        if (rightSum.insert(n + nums[i]).second) {
          // it是大于等于goal-n-nums[i]的第一个迭代器
          auto it = leftSum.lower_bound(goal - n - nums[i]);
          if (it != leftSum.end()) {
            res = std::min(res, std::abs(*it + n + nums[i] - goal));
          }
          if (it != leftSum.begin()) {
            --it;
            res = std::min(res, std::abs(*it + n + nums[i] - goal));
          }
          if (res == 0) return 0;
        }
      }
    }
    return res;
  }
};

TEST(leetcode1755, 1) {
  std::vector<int> nums = {5, -7, 3, 5};
  int goal = 6;
  int expect = 0;
  ASSERT_EQ(Solution().minAbsDifference(nums, goal), expect);
}
