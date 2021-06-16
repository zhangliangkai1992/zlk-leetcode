/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-17 00:13
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int numSquares(int n) {
    // 状态转移方程
    // dp[i] = min(dp[i-k*k]+1)
    std::vector<int> squares;
    for (int i = 1; i * i <= n; ++i) {
      squares.push_back(i * i);
    }
    const int MAX = ~(1 << 31);
    std::vector<int> res(n + 1, MAX);
    res[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < squares.size(); ++j) {
        if (squares[j] <= i) {
          res[i] = std::min(res[i], res[i - squares[j]] + 1);
        } else {
          break;
        }
      }
    }
    return res[n];
  }
};

TEST(leetcode_279, 1) {
  Solution s;
  EXPECT_EQ(s.numSquares(12), 3);
}
