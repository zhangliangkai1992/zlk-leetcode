/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-29 09:08
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(
      const std::vector<int>& candidates, int target) {
    std::vector<std::vector<std::vector<int>>> res(
        target + 1, std::vector<std::vector<int>>());
    res[0] = {{}};
    for (int i = 1; i <= target; ++i) {
      std::vector<std::vector<int>> cur;
      for (auto&& n : candidates) {
        if (i >= n) {
          auto half = res[i - n];
          for (auto&& v : half) {
            // 去重，只能往后加大于等于该值的数字
            if (v.empty() || n >= v.back()) {
              v.push_back(n);
              cur.push_back(v);
            }
          }
        }
      }
      res[i] = cur;
    }
    return res[target];
  }
};

TEST(leetcode_39, 1) {
  std::vector<int> nums = {2, 3, 6, 7};
  int target = 7;
  std::vector<std::vector<int>> expect = {{2, 2, 3}, {7}};
  auto res = Solution().combinationSum(nums, target);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      EXPECT_EQ(res[i][j], expect[i][j]);
    }
  }
}
