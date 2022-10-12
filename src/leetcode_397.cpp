/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-10-12 09:25
 */

#include <gtest/gtest.h>

class Solution {
  std::map<int, int> replaceCount_;

 public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    if (replaceCount_.find(n) != replaceCount_.end()) {
      return replaceCount_[n];
    }
    int res = 0;
    if (n & 1) {
      res = std::min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) +
            2;
    } else {
      res = integerReplacement(n / 2) + 1;
    }
    replaceCount_[n] = res;
    return res;
  }
};

TEST(leetcode, 397) { ASSERT_EQ(Solution().integerReplacement(8), 3); }
