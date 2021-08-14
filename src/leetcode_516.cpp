/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-14 23:14
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int longestPalindromeSubseq(const std::string& s) {
    auto sz = s.size();
    std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));
    for (int i = sz - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < sz; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][sz - 1];
  }
};

TEST(leetcode516, 1) {
  auto s = "bbbab";
  int expect = 4;
  ASSERT_EQ(Solution().longestPalindromeSubseq(s), expect);
}
