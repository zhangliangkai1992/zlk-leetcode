/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-04-29 01:40
 */

#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    int sz = nums.size();
    // value to index
    std::unordered_map<int, int> value_index;
    for (int i = 0; i < sz; ++i) {
      if (value_index.count(target - nums[i]) > 0) {
        return {value_index[target - nums[i]], i};
      }
      value_index[nums[i]] = i;
    }
    return {-1};
  }
};

TEST(leetcode_1, case3) {
  Solution s;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  auto res = s.twoSum(nums, target);
  EXPECT_EQ(res.size(), 2);
  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 1);
}

TEST(leetcode_1, case2) {
  Solution s;
  std::vector<int> nums = {3, 2, 4};
  auto res = s.twoSum(nums, 6);
  EXPECT_EQ(res.size(), 2);
  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 2);
}
