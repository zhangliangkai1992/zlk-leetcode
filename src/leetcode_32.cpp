/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-01 23:39
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
  int getLongest(const std::string& s) {
    // std::cout << s << std::endl;
    int res = 0;
    // 当前左括号比右括号多的个数
    int leftOver = 0;
    // 当前字符串起点
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') {
        --leftOver;
        if (leftOver == 0) {
          res = std::max(res, i - start + 1);
        } else if (leftOver < 0) {
          leftOver = 0;
          start = i + 1;
        }
      } else {
        ++leftOver;
      }
    }
    return res;
  }

 public:
  int longestValidParentheses(const std::string& s) {
    auto res = getLongest(s);
    // 将括号反转
    auto str = s;
    std::reverse(str.begin(), str.end());
    for (auto&& c : str) {
      if (c == ')')
        c = '(';
      else
        c = ')';
    }
    res = std::max(res, getLongest(str));
    return res;
  }
};

TEST(leetcode32, 1) {
  auto s = "(()";
  ASSERT_EQ(Solution().longestValidParentheses(s), 2);
}
TEST(leetcode32, 2) {
  auto s = ")()())";
  ASSERT_EQ(Solution().longestValidParentheses(s), 4);
}
