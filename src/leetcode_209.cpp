/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-08-24 09:40
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minSubArrayLen(int target, const std::vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums[0] >= target) return 1;
    std::vector<int> sums;
    sums.push_back(0);
    int sz = nums.size();
    for (auto &&n : nums) {
      if (n >= target) return 1;
      sums.push_back(sums.back() + n);
    }
    if (sums.back() < target) return 0;
    int res = sz;
    for (int i = 0; i < sz; ++i) {
      if (sums.back() - sums[i] < target) {
        continue;
      }
      auto it =
          std::lower_bound(sums.begin() + i, sums.end(), sums[i] + target);
      int len = std::distance(sums.begin() + i, it);
      res = std::min(res, len);
    }
    return res;
  }
};

TEST(leetcode, 209) {
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  EXPECT_EQ(Solution().minSubArrayLen(target, nums), 2);
}
