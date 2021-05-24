/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-05-24 23:34
 */

#include <gtest/gtest.h>

#include <vector>

class Solution {
  inline int max(int a, int b) { return a < b ? b : a; }

 public:
  int lengthOfLongestSubstring(const std::string &s) {
    int size = s.size();
    // 该字符最后一次出现的位置
    std::vector<int> char_pos(128, -1);
    int res = 0;
    // 当前最左边的字符索引
    int cur_left = -1;
    for (int i = 0; i < size; ++i) {
      if (char_pos[s[i]] > cur_left) {
        cur_left = char_pos[s[i]];
      }
      int diff = i - max(cur_left, char_pos[s[i]]);
      res = max(diff, res);
      char_pos[s[i]] = i;
    }
    return res;
  }
};
TEST(leetcode_3, 1) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring(""), 0);
  EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
  EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
}
