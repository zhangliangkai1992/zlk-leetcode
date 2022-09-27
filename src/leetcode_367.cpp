/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-09-26 09:13
 */

#include <gtest/gtest.h>
class Solution {
 public:
  bool isPerfectSquare(int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
      int mid = (high + low) / 2;
      const auto product = 1L * mid * mid;
      if (product == n) {
        return true;
      } else if (product < n) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};
TEST(leetcode, 367) { ASSERT_TRUE(Solution().isPerfectSquare(16)); }
