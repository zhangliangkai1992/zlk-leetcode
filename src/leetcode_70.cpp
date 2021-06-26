/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 15:39
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int climbStairs(int n) {
    int64_t a = 1;
    int64_t b = 1;
    for (int i = 0; i < n; ++i) {
      int64_t c = a + b;
      a = b;
      b = c;
    }
    return static_cast<int>(a);
  }
};
TEST(leetcode_70, 1) {
  EXPECT_EQ(Solution().climbStairs(2), 2);
  EXPECT_EQ(Solution().climbStairs(3), 3);
}
