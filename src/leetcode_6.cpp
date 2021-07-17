/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-17 22:15
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::string convert(const std::string& s, int numRows) {
    if (numRows == 1) return s;
    std::vector<std::string> all(numRows);
    int current = 0;
    int downDir = true;
    for (auto&& c : s) {
      all[current] += c;
      if (downDir) {
        ++current;
        if (current == numRows) {
          current = numRows - 2;
          downDir = false;
        }
      } else {
        --current;
        if (current == -1) {
          current = 1;
          downDir = true;
        }
      }
    }
    std::string res;
    for (auto&& str : all) {
      res += str;
    }
    return res;
  }
};

TEST(leetcode6, 1) {
  std::string s = "PAYPALISHIRING";
  std::string expect = "PAHNAPLSIIGYIR";
  ASSERT_EQ(Solution().convert(s, 3), expect);
}
