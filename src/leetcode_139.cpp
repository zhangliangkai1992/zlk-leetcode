/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-28 22:21
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  bool wordBreak(const std::string& s,
                 const std::vector<std::string>& wordDict) {
    std::unordered_map<std::string, bool> words;
    for (auto&& w : wordDict) {
      words[w] = true;
    }
    // dp[i]:表示从0开始长度为i的子字符串是否可由字典构成
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (dp[j]) {
          auto cur = s.substr(j, i - j);
          if (words[cur]) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[s.size()];
  }
};

TEST(leetcode_139, 1) {
  std::string s = "leetcode";
  std::vector<std::string> wordDict = {"leet", "code"};
  EXPECT_EQ(Solution().wordBreak(s, wordDict), true);
}
