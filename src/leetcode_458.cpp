/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-12 22:30
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    // x pig T tests的状态数为(T+1)^x，即每只猪代表一个维度，测试T次
    // min(x) such that (T+1)^x >= N
    auto times = (minutesToTest + minutesToDie - 1) / minutesToDie;
    int x = 0;
    int64_t current = 1;
    while (current < buckets) {
      ++x;
      current *= (times + 1);
    }
    return x;
  }
};

TEST(leetcode, 458) {
  int buckets = 1000;
  int minutesToDie = 15;
  int minutesToTest = 60;
  int expect = 5;
  ASSERT_EQ(Solution().poorPigs(buckets, minutesToDie, minutesToTest), expect);
}
