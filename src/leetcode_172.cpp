/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024-02-19 21:58
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int trailingZeroes(int n) {
    int twos = 0;
    int fives = 0;
    for (int i = 2; i <= n; i += 2) {
      auto current = i;
      while (current % 2 == 0) {
        ++twos;
        current = current / 2;
      }
    }
    for (int i = 5; i <= n; i += 5) {
      int current = i;
      while (current % 5 == 0) {
        current = current / 5;
        ++fives;
      }
    }
    return std::min(twos, fives);
  }
};

TEST(leetcode, 172) {
  int n = 30;
  int res = Solution().trailingZeroes(n);
  int expect = 7;
  ASSERT_EQ(res, expect);
}
