/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-13 22:58
 */
#include <gtest/gtest.h>

class Solution {
  void dfs(std::vector<int> *current, std::vector<bool> *has_put,
           const std::vector<int> &nums, std::vector<std::vector<int>> *res) {
    if (nums.size() == current->size()) {
      res->push_back(*current);
      return;
    }
    auto sz = nums.size();
    for (decltype(sz) i = 0; i < nums.size(); ++i) {
      if (!has_put->at(i)) {
        has_put->at(i) = true;
        current->push_back(nums[i]);
        dfs(current, has_put, nums, res);
        has_put->at(i) = false;
        current->pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<bool> has_put(nums.size(), false);
    std::vector<int> current;
    dfs(&current, &has_put, nums, &res);
    return res;
  }
};

TEST(leetcode_46, 1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> expect = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                          {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  Solution s;
  auto res = s.permute(nums);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++i) {
      EXPECT_EQ(res[i][j], expect[i][j]);
    }
  }
}
