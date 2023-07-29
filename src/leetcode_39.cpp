/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 19:50
 */

#include <include/leetcode_util.h>

class Solution {
  void dfs(int target) {
    if (target == 0) {
      res_.push_back(path_);
      return;
    }
    if (target < 0) {
      return;
    }
    for (auto &&n : ele_) {
      if (path_.empty() || n >= path_.back()) {
        path_.push_back(n);
        dfs(target - n);
        path_.pop_back();
      }
    }
  }
  std::set<int> ele_;
  std::vector<std::vector<int>> res_;
  std::vector<int> path_;

 public:
  std::vector<std::vector<int>> combinationSum(const std::vector<int> &nums,
                                               int target) {
    for (auto &&n : nums) {
      ele_.insert(n);
    }
    dfs(target);
    return res_;
  }
};

TEST(leetcode, 39) {
  int target = 7;
  const std::vector<int> nums = {2, 3, 6, 7};
  auto res = Solution().combinationSum(nums, target);
  decltype(res) expect = {{2, 2, 3}, {7}};
  AssertMatrix(expect, res);
}
