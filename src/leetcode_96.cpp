/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 16:25
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> res(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      res[i] = 0;
      for (int j = 0; j < i; ++j) {
        res[i] += res[j] * res[i - j - 1];
      }
    }
    return res[n];
  }
};

TEST(leetcode_96, 1) { EXPECT_EQ(Solution().numTrees(3), 5); }
