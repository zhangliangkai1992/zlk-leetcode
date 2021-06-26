/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 15:39
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int climbStairs(int n) {
    long a = 1;
    long b = 1;
    for (int i = 0; i < n; ++i) {
      long c = a + b;
      a = b;
      b = c;
    }
    return a;
  }
};
TEST(leetcode_70, 1) {
  EXPECT_EQ(Solution().climbStairs(2), 2);
  EXPECT_EQ(Solution().climbStairs(3), 3);
}
