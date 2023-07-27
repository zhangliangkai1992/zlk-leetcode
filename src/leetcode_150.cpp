/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-14 00:21
 */

#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  int evalRPN(const std::vector<std::string> &tokens) {
    std::stack<int> st;
    for (auto &&t : tokens) {
      int op1 = 0;
      int op2 = 0;
      if (t == "+") {
        op2 = st.top();
        st.pop();
        op1 = st.top();
        st.pop();
        st.push(op1 + op2);
      } else if (t == "-") {
        op2 = st.top();
        st.pop();
        op1 = st.top();
        st.pop();
        st.push(op1 - op2);
      } else if (t == "*") {
        op2 = st.top();
        st.pop();
        op1 = st.top();
        st.pop();
        st.push(op1 * op2);
      } else if (t == "/") {
        op2 = st.top();
        st.pop();
        op1 = st.top();
        st.pop();
        st.push(op1 / op2);
      } else {
        st.push(std::stoi(t));
      }
    }
    return st.top();
  }
};

TEST(leetcode, 150) {
  std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  int expect = 9;
  ASSERT_EQ(Solution().evalRPN(tokens), expect);
}
