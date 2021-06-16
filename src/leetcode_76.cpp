/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-14 01:08
 */
#include <gtest/gtest.h>

#include <unordered_map>

// Hard
class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> charCount;
    for (auto&& c : t) {
      ++charCount[c];
    }
    int counter = t.size();
    // 滑动窗口
    int low = 0;
    int high = 0;
    // 结果的起点
    int start = 0;
    // 结果的长度
    auto INT_MAX = ~(1 << 31);
    int len = INT_MAX;
    while (high < s.size()) {
      if (charCount[s[high++]]-- > 0) {
        --counter;
      }
      while (counter == 0) {
        if (high - low < len) {
          len = high - low;
          start = low;
        }
        if (charCount[s[low++]]++ == 0) {
          ++counter;
        }
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

TEST(leetcode_76, 1) {
  Solution s;
  EXPECT_EQ(s.minWindow("ADOBECODEBANC", "ABC"), "BANC");
  EXPECT_EQ(s.minWindow("a", "a"), "a");
  EXPECT_EQ(s.minWindow("a", "aa"), "");
}
