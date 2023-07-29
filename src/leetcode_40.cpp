/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 20:03
 */

#include <include/leetcode_util.h>

class Solution {
  std::map<int, int> ele_count_;
  std::vector<std::vector<int>> res_;
  std::vector<int> path_;
  void dfs(int target) {
    if (target == 0) {
      res_.push_back(path_);
      return;
    }
    if (target < 0) {
      return;
    }
    for (auto &&item : ele_count_) {
      if (path_.empty() || (item.first >= path_.back() && item.second > 0)) {
        path_.push_back(item.first);
        --item.second;
        dfs(target - item.first);
        ++item.second;
        path_.pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<int>> combinationSum2(const std::vector<int> &nums,
                                                int target) {
    for (auto &&n : nums) {
      ++ele_count_[n];
    }
    dfs(target);
    return res_;
  }
};

TEST(leetcode, 40) {
  const std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  auto res = Solution().combinationSum2(nums, target);
  decltype(res) expect = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  AssertMatrix(res, expect);
}
