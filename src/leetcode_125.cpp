/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-21 23:56
 */

#include <include/leetcode_util.h>

class Solution {
  static bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
  }
  static bool check(char c1, char c2) {
    return c1 == c2 ||
           (c1 >= 'a' && c1 <= 'z' && c2 >= 'A' && c2 <= 'Z' &&
            c1 - c2 == 'a' - 'A') ||
           (c2 >= 'a' && c2 <= 'z' && c1 >= 'A' && c1 <= 'Z' &&
            c2 - c1 == 'a' - 'A');
  }

 public:
  bool isPalindrome(const std::string &s) {
    int low = 0;
    int high = s.size() - 1;
    while (low <= high) {
      while (low <= high && !isAlpha(s[low])) ++low;
      while (low <= high && !isAlpha(s[high])) --high;
      if (low <= high && !check(s[low], s[high])) {
        return false;
      }
      ++low;
      --high;
    }
    return true;
  }
};

TEST(leetcode, 125) {
  std::string s = "A man, a plan, a canal: Panama";
  ASSERT_TRUE(Solution().isPalindrome(s));
  std::string s2 = "0P";
  ASSERT_FALSE(Solution().isPalindrome(s2));
}
