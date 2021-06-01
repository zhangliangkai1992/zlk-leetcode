
/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-02 00:52
 */
#include <gtest/gtest.h>

#include <stack>

class Solution {
  inline bool open_bracket(char c) { return c == '(' || c == '[' || c == '{'; }
  inline bool pair_bracket(char c1, char c2) {
    return c1 == '(' && c2 == ')' || c1 == '[' && c2 == ']' ||
           c1 == '{' && c2 == '}';
  }

 public:
  bool isValid(const std::string& s) {
    std::stack<char> st;
    for (auto&& c : s) {
      if (open_bracket(c)) {
        st.push(c);
      } else if (!st.empty() && pair_bracket(st.top(), c)) {
        st.pop();
      } else {
        return false;
      }
    }
    return st.empty();
  }
};

TEST(leetcode_20, 1) {
  Solution s;
  auto res = s.isValid("()");
  EXPECT_EQ(res, true);
}

TEST(leetcode_20, 2) {
  Solution s;
  auto res = s.isValid("[");
  EXPECT_EQ(res, false);
}
