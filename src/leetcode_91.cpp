/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-11 16:37
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  int numDecodings(const std::string& s) {
    auto sz = static_cast<int>(s.size());
    if (!sz) return 0;
    int last = 1;
    int res = s[0] != '0';
    for (int i = 1; i < sz; ++i) {
      int next = 0;
      if (s[i] > '0' && s[i] <= '9') {
        next += res;
      }
      int value = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if (value >= 10 && value <= 26) {
        next += last;
      }
      last = res;
      res = next;
    }
    return res;
  }
};

TEST(leetcode91, 1) {
  std::string s = "12";
  ASSERT_EQ(Solution().numDecodings(s), 2);
}
