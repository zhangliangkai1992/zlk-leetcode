/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 09:43
 */
#include <gtest/gtest.h>

class Solution {
  std::pair<int, int> extendsPalindrome(const std::string& s, int low,
                                        int high) {
    while (low >= 0 && high < s.size() && s[low] == s[high]) {
      --low;
      ++high;
    }
    return {low + 1, high - 1};
  }

 public:
  std::string longestPalindrome(const std::string& s) {
    // std::cout << std::endl;
    auto sz = s.size();
    if (sz < 2) return s;
    int maxLen = 1;
    int pos = 0;
    for (int i = 0; i < sz; ++i) {
      auto p = extendsPalindrome(s, i, i);
      if (p.second - p.first + 1 > maxLen) {
        maxLen = p.second - p.first + 1;
        pos = p.first;
      }
      p = extendsPalindrome(s, i, i + 1);
      if (p.second - p.first + 1 > maxLen) {
        maxLen = p.second - p.first + 1;
        pos = p.first;
      }
    }
    return s.substr(pos, maxLen);
  }
};
TEST(leetcode5, 1) {
  auto s = "babad";
  ASSERT_EQ(Solution().longestPalindrome(s), "bab");
}
TEST(leetcode5, 2) {
  auto s = "aacabdkacaa";
  ASSERT_EQ(Solution().longestPalindrome(s), "aca");
}
