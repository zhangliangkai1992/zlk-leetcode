/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-15 22:21
 */

#include <gtest/gtest.h>

#include <numeric>

class Solution {
 public:
  bool makesquare(const std::vector<int> &sticks) {
    auto sum = std::accumulate(sticks.begin(), sticks.end(), 0);
    if (sum % 4) {
      return false;
    }
    int n = sticks.size();
    std::vector<int> usedMasks;
    std::vector<bool> halfValid(1 << n, false);
    int all = (1 << n) - 1;
    auto target = sum / 4;
    for (int mask = 0; mask <= all; ++mask) {
      int partSum = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          partSum += sticks[i];
        }
      }
      if (partSum == target) {
        for (auto &&used : usedMasks) {
          if (!(mask & used)) {
            auto half = mask | used;
            halfValid[half] = true;
            if (halfValid[all ^ half]) {
              return true;
            }
          }
        }
        usedMasks.push_back(mask);
      }
    }
    return false;
  }
};

TEST(leetcode473, 1) {
  std::vector<int> nums = {3, 1, 3, 3, 10, 7, 10, 3, 6, 9, 10, 3, 7, 6, 7};
  EXPECT_TRUE(Solution().makesquare(nums));
}
