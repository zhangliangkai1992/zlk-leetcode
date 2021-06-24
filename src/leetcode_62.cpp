/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-24 23:05
 */
#include <gtest/gtest.h>
class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<int> res(n, 1);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        res[j] += res[j - 1];
      }
    }
    return res[n - 1];
  }
};
TEST(leetcode_62, 1) {
  Solution s;
  EXPECT_EQ(s.uniquePaths(3, 7), 28);
}
