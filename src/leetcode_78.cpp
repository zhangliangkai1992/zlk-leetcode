/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-16 23:28
 */
#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    int sz = nums.size();
    int up = 1 << sz;
    for (int i = 0; i < up; ++i) {
      std::vector<int> cur;
      for (int j = 0; j < sz; ++j) {
        if ((i >> j) & 1) {
          cur.push_back(nums[j]);
        }
      }
      res.push_back(cur);
    }
    return res;
  }
};

TEST(leetcode_78, 1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> expect = {{},  {1},    {2},    {1, 2},
                                          {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  Solution s;

  auto res = s.subsets(nums);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      EXPECT_EQ(res[i][j], expect[i][j]);
    }
  }
}
