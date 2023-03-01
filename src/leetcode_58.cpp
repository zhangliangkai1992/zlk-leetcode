/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-02 00:21
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int lengthOfLastWord(const std::string &s) {
    int high = s.size() - 1;
    while (high >= 0 && s[high] == ' ') {
      --high;
    }
    int low = high;
    while (low >= 0 && s[low] != ' ') {
      --low;
    }
    return high - low;
  }
};

TEST(leetcode, 58) {
  std::string s = "Hello World";
  int expect = 5;
  ASSERT_EQ(Solution().lengthOfLastWord(s), expect);
}
