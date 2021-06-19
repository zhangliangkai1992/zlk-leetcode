/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 10:15
 */
#include <gtest/gtest.h>

class Solution {
 public:
  // 计数排序
  void sortColors(std::vector<int>* p_nums) {
    std::vector<int> n_count(3, 0);
    for (auto&& n : *p_nums) {
      ++n_count[n];
    }
    for (int i = 0; i < n_count[0]; ++i) {
      p_nums->at(i) = 0;
    }
    for (int i = n_count[0]; i < n_count[0] + n_count[1]; ++i) {
      p_nums->at(i) = 1;
    }
    for (int i = n_count[0] + n_count[1]; i < p_nums->size(); ++i) {
      p_nums->at(i) = 2;
    }
  }
};

TEST(leetcode_75, 1) {
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};
  std::vector<int> expect = {0, 0, 1, 1, 2, 2};
  EXPECT_EQ(nums.size(), expect.size());
  Solution().sortColors(&nums);
  for (int i = 0; i < nums.size(); ++i) {
    EXPECT_EQ(nums[i], expect[i]);
  }
}
