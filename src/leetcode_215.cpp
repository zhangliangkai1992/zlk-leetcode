/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-06 23:26
 */
#include <gtest/gtest.h>

#include <queue>

class Solution {
 public:
  int findKthLargest(const std::vector<int>& vec, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    auto sz = vec.size();
    for (auto&& n : vec) {
      que.push(n);
      if (que.size() > k) {
        que.pop();
      }
    }
    return que.top();
  }
};

TEST(leetcode215, 1) {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  ASSERT_EQ(Solution().findKthLargest(nums, 2), 5);
}
TEST(leetcode215, 2) {
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  ASSERT_EQ(Solution().findKthLargest(nums, 4), 4);
}
TEST(leetcode215, 3) {
  std::vector<int> nums = {2, 1};
  ASSERT_EQ(Solution().findKthLargest(nums, 2), 1);
}
