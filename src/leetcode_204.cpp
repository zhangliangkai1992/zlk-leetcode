/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-10-22 11:37
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int countPrimes(int n) {
    std::vector<bool> notPrime(n, false);
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (!notPrime[i]) {
        ++count;
        for (int j = 2; i * j < n; ++j) {
          notPrime[i * j] = true;
        }
      }
    }
    return count;
  }
};

TEST(leetcode, 204) { ASSERT_EQ(Solution().countPrimes(499979), 41537); }
