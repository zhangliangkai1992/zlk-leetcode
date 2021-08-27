/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-27 00:16
 */

#include <gtest/gtest.h>

#include <queue>

class Solution {
 public:
  int maxResult(const std::vector<int> &nums, int k) {
    auto sz = nums.size();
    std::deque<int> que = {0};
    std::vector<int> res(sz, 0);
    res[0] = nums[0];
    for (int i = 1; i < sz; ++i) {
      if (que.front() < i - k) que.pop_front();
      res[i] = nums[i] + res[que.front()];
      while (!que.empty() && res[que.back()] <= res[i]) {
        que.pop_back();
      }
      que.push_back(i);
    }
    return res.back();
  }
};

TEST(leetcode1696, 1) {
  std::vector<int> nums = {1, -1, -2, 4, -7, 3};
  int k = 2;
  int expect = 7;
  ASSERT_EQ(Solution().maxResult(nums, k), expect);
}
