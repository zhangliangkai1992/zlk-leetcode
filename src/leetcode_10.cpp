/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 10:34
 */
#include <gtest/gtest.h>

class Solution {
 public:
  // dp[i][j]=true表示s的字串[0,i)匹配p的子串[0,j)
  bool isMatch(const std::string& s, const std::string& p) {
    auto sLen = s.size();
    auto pLen = p.size();
    std::vector<std::vector<bool>> dp(sLen + 1,
                                      std::vector<bool>(pLen + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= sLen; ++i) {
      for (int j = 1; j <= pLen; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] =
              dp[i][j - 2] ||
              // dp[i-1][j]匹配且s[i-1]和p[j-2]匹配
              (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        } else {
          dp[i][j] = i && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }
    return dp[sLen][pLen];
  }
};

TEST(leetcode10, 1) { ASSERT_EQ(Solution().isMatch("aa", "a"), false); }
