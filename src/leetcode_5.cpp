/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-25 23:59
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  std::string longestPalindrome(const std::string &s) {
    std::string res;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      int low = i;
      int high = i;
      while (low >= 0 && high < sz && s[low] == s[high]) {
        --low;
        ++high;
      }
      int len = high - low - 1;
      if (len > res.size()) {
        res = s.substr(low + 1, len);
      }
      low = i;
      high = i + 1;
      while (low >= 0 && high < sz && s[low] == s[high]) {
        --low;
        ++high;
      }
      len = high - low - 1;
      if (len > res.size()) {
        res = s.substr(low + 1, len);
      }
    }
    return res;
  }
};

TEST(leetcode, 5) {
  std::string s = "cbbd";
  auto res = Solution().longestPalindrome(s);
  decltype(res) expect = "bb";
  ASSERT_EQ(res, expect);
}
