/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-03 23:07
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int integerBreak(int n) {
    std::unordered_map<int, int> cache;
    cache[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        cache[i] = std::max(
            cache[i], std::max(j, cache[j]) * std::max(i - j, cache[i - j]));
      }
    }
    return cache[n];
  }
};

TEST(leetcode343, 1) { ASSERT_EQ(Solution().integerBreak(10), 36); }
