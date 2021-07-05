/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-06 00:10
 */
#include <gtest/gtest.h>

#include <stack>

class Solution {
 public:
  std::string decodeString(const std::string& s) {
    std::stack<std::string> st;
    std::stack<int> stRepeat;
    int i = 0;
    while (i < s.size()) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        auto j = i;
        while (j < s.size() && s[j] >= 'a' && s[j] <= 'z') ++j;
        st.push(s.substr(i, j - i));
        i = j;
      } else if (s[i] >= '0' && s[i] <= '9') {
        auto j = i;
        while (j < s.size() && s[j] >= '0' && s[j] <= '9') ++j;
        stRepeat.push(std::stoi(s.substr(i, j - i)));
        i = j;
      } else if (s[i] == ']') {
        auto count = stRepeat.top();
        stRepeat.pop();
        std::string str;
        while (st.top() != "[") {
          str = st.top() + str;
          st.pop();
        }
        st.pop();
        std::string repeatStr;
        for (int i = 0; i < count; ++i) {
          repeatStr += str;
        }
        st.push(repeatStr);
        ++i;
      } else {
        st.push("[");
        ++i;
      }
    }
    std::string res;
    while (!st.empty()) {
      res = st.top() + res;
      st.pop();
    }
    return res;
  }
};

TEST(leetcode394, 1) {
  auto s = "abc3[cd]xyz";
  auto res = Solution().decodeString(s);
  decltype(res) expect = "abccdcdcdxyz";
  ASSERT_EQ(res, expect);
}

TEST(leetcode394, 2) {
  auto s = "3[a2[c]]";
  auto res = Solution().decodeString(s);
  decltype(res) expect = "accaccacc";
  ASSERT_EQ(res, expect);
}
