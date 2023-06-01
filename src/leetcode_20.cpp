/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-02 23:28
 */

#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  bool isValid(const std::string &s) {
    std::stack<char> st;
    for (auto &&c : s) {
      switch (c) {
        case '(':
          st.push(c);
          break;
        case ')':
          if (st.empty() || st.top() != '(') {
            return false;
          }
          st.pop();
          break;
        case '[':
          st.push(c);
          break;
        case ']':
          if (st.empty() || st.top() != '[') {
            return false;
          }
          st.pop();
          break;
        case '{':
          st.push(c);
          break;
        case '}':
          if (st.empty() || st.top() != '{') {
            return false;
          }
          st.pop();
          break;
      }
    }
    return st.empty();
  }
};

TEST(leetcode, 20) {
  std::string s = "([)]";
  ASSERT_FALSE(Solution().isValid(s));
}
