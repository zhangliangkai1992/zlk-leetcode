/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-16 00:27
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int brokenCalc(int64_t start, int64_t target) {
    return start >= target
               ? start - target
               : 1 + target % 2 + brokenCalc(start, (target + 1) >> 1);
  }
};

TEST(leetcode, 991) { ASSERT_EQ(Solution().brokenCalc(1, 1000000000), 39); }
