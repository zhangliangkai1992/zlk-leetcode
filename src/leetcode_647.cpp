/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 20:05
 */
#include <gtest/gtest.h>

class Solution {
  int extendString(const std::string& s, int low, int high) {
    int res = 0;
    while (low >= 0 && high < s.size() && s[low] == s[high]) {
      --low;
      ++high;
      ++res;
    }
    return res;
  }

 public:
  int countSubstrings(const std::string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      res += extendString(s, i, i);
      res += extendString(s, i, i + 1);
    }
    return res;
  }
};
TEST(leetcode647, 1) { ASSERT_EQ(Solution().countSubstrings("aaa"), 6); }
