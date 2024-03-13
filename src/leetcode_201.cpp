/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024-02-19 22:52
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    while (right > left) {
      right = right & (right - 1);
    }
    return right & left;
  }
};

TEST(leetcode, 201) {
  int left = 1;
  int right = 1;
  int expect = 1;
  ASSERT_EQ(Solution().rangeBitwiseAnd(left, right), expect);
}
