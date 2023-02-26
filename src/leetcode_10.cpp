/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-26 09:44
 */

#include <include/leetcode_util.h>

class Solution {
  bool isMatch(const char *s, const char *p) {
    if (*p == '\0') {
      return *s == '\0';
    }
    if (p[1] != '*') {
      if (*p == *s || (*p == '.' && *s != '\0')) {
        return isMatch(s + 1, p + 1);
      } else {
        return false;
      }
    }
    while (*p == *s || (*p == '.' && *s != '\0')) {
      if (isMatch(s, p + 2)) {
        return true;
      }
      ++s;
    }
    return isMatch(s, p + 2);
  }

 public:
  bool isMatch(const std::string &s, const std::string &p) {
    return isMatch(s.c_str(), p.c_str());
  }
};

TEST(leetcode, 10) {
  std::string s = "mississippi";
  std::string p = "mis*is*ip*.";
  ASSERT_TRUE(Solution().isMatch(s, p));
}
