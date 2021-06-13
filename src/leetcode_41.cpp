/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-13 22:05
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int firstMissingPositive(const std::vector<int>& other) {
    auto nums = other;
    int sz = nums.size();
    // i = nums[i] - 1 ===> 索引为i的存储值为i+1
    for (int i = 0; i < sz; ++i) {
      while (nums[i] > 0 && nums[i] - 1 != i && nums[i] - 1 >= 0 &&
             nums[i] - 1 < sz && nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (nums[i] - 1 != i) {
        return i + 1;
      }
    }
    return sz + 1;
  }
};
TEST(leetcode_41, 1) {
  Solution s;
  std::vector<int> nums = {1, 2, 0};
  EXPECT_EQ(s.firstMissingPositive(nums), 3);
}
TEST(leetcode_41, 2) {
  Solution s;
  std::vector<int> nums = {3, 4, -1, 1};
  EXPECT_EQ(s.firstMissingPositive(nums), 2);
}
TEST(leetcode_41, 3) {
  Solution s;
  std::vector<int> nums = {7, 8, 9, 11, 12};
  EXPECT_EQ(s.firstMissingPositive(nums), 1);
}
TEST(leetcode_41, 4) {
  Solution s;
  std::vector<int> nums = {1};
  EXPECT_EQ(s.firstMissingPositive(nums), 2);
}
TEST(leetcode_41, 5) {
  Solution s;
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(s.firstMissingPositive(nums), 2);
}
TEST(leetcode_41, 6) {
  Solution s;
  std::vector<int> nums = {2, 1};
  EXPECT_EQ(s.firstMissingPositive(nums), 3);
}
