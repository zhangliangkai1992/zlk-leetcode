/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-01 23:08
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int countDigitOne(int n) {
    int ones = 0;
    // 每位进行计算，从低到高
    for (int64_t m = 1; m <= n; m *= 10) {
      int a = n / m;
      int b = n % m;
      // pow(10,k)=m
      // 区间[0,10],总共11个数
      // 第k位不为1时，新增(a/10+1)*m个one
      // 第k位为1时，新增a/10*m+b+1个one
      ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
  }
};

TEST(leetcode233, 1) { ASSERT_EQ(Solution().countDigitOne(99), 20); }
