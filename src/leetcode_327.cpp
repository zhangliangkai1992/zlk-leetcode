/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-08-26 09:34
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int countRangeSum(const std::vector<int> &nums, int low, int high) {
    // TODO 未完成
    std::vector<int> sums = {0};
    for (auto &&n : nums) {
      sums.push_back(sums.back() + n);
    }
    int sz = nums.size();
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        int s = sums[j] - sums[i];
        if (low <= s && s <= high) ++res;
      }
    }
    return res;
  }
};
TEST(leetcode, 327) {
  std::vector<int> nums = {-1, 1};
  int low = -1;
  int high = 1;
  ASSERT_EQ(Solution().countRangeSum(nums, low, high), 1);
}
