/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-28 16:32
 */

#include <gtest/gtest.h>

#include <stack>

class Solution {
 public:
  int divide(int64_t dividend, int64_t divisor) {
    bool pos = true;
    if (dividend < 0) {
      dividend = -dividend;
      pos = !pos;
    }
    if (divisor < 0) {
      divisor = -divisor;
      pos = !pos;
    }
    std::stack<int64_t> st;
    auto current = divisor;
    int64_t factor = 1;
    while (current <= dividend) {
      st.push(current);
      current = (current << 1);
      factor = (factor << 1);
    }
    factor = (factor >> 1);
    int64_t res = 0;
    while (dividend >= divisor) {
      if (dividend >= st.top()) {
        res += factor;
        dividend -= st.top();
      } else {
        st.pop();
        factor = (factor >> 1);
      }
    }
    if (!pos) {
      res = -res;
    }
    const int MAX = ~(1 << 31);
    if (res > MAX || res < ~MAX) {
      return MAX;
    }
    return res;
  }
};

TEST(leetcode29, 1) { ASSERT_EQ(Solution().divide(10, -3), -3); }
