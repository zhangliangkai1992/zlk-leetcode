/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-02 22:08
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minCut(const std::string& s) {
    auto sz = s.size();
    const int MAX = ~(1 << 31);
    // dp[i]表示长度为i的所需要的最小分割次数
    std::vector<int> dp(sz + 1);
    for (int i = 0; i <= sz; ++i) {
      dp[i] = i - 1;
    }
    std::vector<std::vector<bool>> isPalin(sz, std::vector<bool>(sz, false));
    for (int i = 1; i < sz; ++i) {
      for (int j = i; j >= 0; --j) {
        if (s[i] == s[j] && (i - j < 2 || isPalin[i - 1][j + 1])) {
          isPalin[i][j] = true;
          dp[i + 1] = std::min(dp[i + 1], 1 + dp[j]);
        }
      }
    }
    return dp.back();
  }
};

TEST(leetcode132, 1) {
  std::string s = "ab";
  ASSERT_EQ(Solution().minCut(s), 1);
}
