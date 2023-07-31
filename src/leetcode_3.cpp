/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-31 22:02
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string &s) {
    int res = 0;
    int sz = s.size();
    int low = 0;
    std::unordered_map<char, int> char_pos;
    for (int i = 0; i < sz; ++i) {
      if (char_pos.find(s[i]) != char_pos.end()) {
        low = std::max(low, char_pos[s[i]] + 1);
      }
      res = std::max(res, i - low + 1);
      char_pos[s[i]] = i;
    }
    return res;
  }
};

TEST(leetcode, 3) {
  auto s = "abcabcbb";
  int expect = 3;
  EXPECT_EQ(expect, Solution().lengthOfLongestSubstring(s));
}
