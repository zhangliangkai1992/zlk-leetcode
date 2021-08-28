/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-28 17:00
 */

#include <gtest/gtest.h>

#include <unordered_set>

class Solution {
  void dfs(int target, const std::vector<int> &nums, int index,
           std::vector<int> *path, std::vector<std::vector<int>> *res) {
    if (target == 0) {
      res->push_back(*path);
      return;
    }
    if (index >= nums.size() || target < 0) {
      return;
    }
    path->push_back(nums[index]);
    dfs(target - nums[index], nums, index + 1, path, res);
    path->pop_back();
    auto next = index + 1;
    while (next < nums.size() && nums[next] == nums[index]) ++next;
    dfs(target, nums, next, path, res);
  }

 public:
  std::vector<std::vector<int>> combinationSum2(const std::vector<int> &nums,
                                                int target) {
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());
    std::vector<int> path;
    int index = 0;
    std::vector<std::vector<int>> res;
    dfs(target, sortedNums, index, &path, &res);
    return res;
  }
};

TEST(leetcode40, 1) {
  std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  auto res = Solution().combinationSum2(nums, target);
  decltype(res) expect = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
}
