/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-15 23:52
 */

#include <gtest/gtest.h>
#include <math.h>

#include <queue>

class Solution {
  std::unordered_map<int, int> cache_;

 public:
  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }
    if (cache_[n]) {
      return cache_[n];
    }
    if (!(n & 1)) {
      return cache_[n] = minSteps(n >> 1) + 2;
    }
    int res = n;
    int up = sqrt(n);
    for (int i = 3; i <= up; ++i) {
      if (n % i == 0) {
        res = std::min(res, n / i + minSteps(i));
        res = std::min(res, i + minSteps(n / i));
      }
    }
    return cache_[n] = res;
  }
};

TEST(leetcode, 650) { ASSERT_EQ(Solution().minSteps(20), 9); }
