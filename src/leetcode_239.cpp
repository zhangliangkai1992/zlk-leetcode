/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-13 21:18
 */
#include <gtest/gtest.h>

#include <queue>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    // 优先级队列（使用大顶堆）
    int sz = nums.size();
    auto cmp = [&nums](int i, int j) { return nums[i] < nums[j]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> que(cmp);
    for (int i = 0; i < sz && i < k; ++i) {
      que.push(i);
    }
    std::vector<int> res;
    res.push_back(nums[que.top()]);
    for (int i = k; i < sz; ++i) {
      while (!que.empty() && i - que.top() >= k) {
        que.pop();
      }
      que.push(i);
      res.push_back(nums[que.top()]);
    }
    return res;
  }
};

TEST(leetcode_239, 1) {
  Solution s;
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  auto res = s.maxSlidingWindow(nums, 3);
  std::vector<int> expect = {3, 3, 5, 5, 6, 7};
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}
TEST(leetcode_239, 2) {
  Solution s;
  std::vector<int> nums = {1, -1};
  auto res = s.maxSlidingWindow(nums, 1);
  std::vector<int> expect = nums;
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}
