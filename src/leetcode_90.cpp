/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-28 19:17
 */

#include <gtest/gtest.h>

class Solution {
  void dfs(const std::vector<int> &nums, int i, std::vector<int> *pCurrent,
           std::vector<std::vector<int>> *pRes) {
    auto sz = nums.size();
    if (i >= sz) {
      pRes->push_back(*pCurrent);
      return;
    }

    int next = i + 1;
    while (next < sz && nums[next] == nums[i]) ++next;
    dfs(nums, next, pCurrent, pRes);

    pCurrent->push_back(nums[i]);
    dfs(nums, i + 1, pCurrent, pRes);
    pCurrent->pop_back();
  }

 public:
  std::vector<std::vector<int>> subsetsWithDup(const std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> current;
    dfs(sorted, 0, &current, &res);
    return res;
  }
};

TEST(leetcode90, 1) {
  std::vector<int> nums = {1, 2, 2};
  auto res = Solution().subsetsWithDup(nums);
  decltype(res) expect = {
      {}, {2}, {2, 2}, {1}, {1, 2}, {1, 2, 2},
  };
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
}
