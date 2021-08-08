/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-08 15:47
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int findMaxForm(const std::vector<std::string>& strs, int m, int n) {
    auto sz = strs.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      int one = 0;
      int zero = 0;
      for (int s = 0; s < strs[i].size(); ++s) {
        if ('1' == strs[i][s]) ++one;
        if ('0' == strs[i][s]) ++zero;
      }
      for (int j = m; j >= zero; --j) {
        for (int k = n; k >= one; --k) {
          dp[j][k] = std::max(dp[j][k], 1 + dp[j - zero][k - one]);
          res = std::max(res, dp[j][k]);
        }
      }
    }
    return res;
  }
};

TEST(leetcode474, 1) {
  std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5;
  int n = 3;
  int expect = 4;
  ASSERT_EQ(Solution().findMaxForm(strs, m, n), expect);
}
