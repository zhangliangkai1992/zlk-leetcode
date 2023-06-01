/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-02 23:48
 */

#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  int longestValidParentheses(const std::string &s) {
    int sz = s.size();
    int res = 0;
    int last = -1;
    std::stack<int> lefts;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '(') {
        lefts.push(i);
      } else {
        if (lefts.empty()) {
          last = i;
        } else {
          lefts.pop();
          if (lefts.empty()) {
            res = std::max(res, i - last);
          } else {
            res = std::max(res, i - lefts.top());
          }
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 32) {
  std::string s = "()(()";
  int expect = 2;
  ASSERT_EQ(Solution().longestValidParentheses(s), expect);
}
