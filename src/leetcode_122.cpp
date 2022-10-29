/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-10-24 09:15
 */

#include <gtest/gtest.h>

#include <stack>

class Solution {
 public:
  int maxProfit(const std::vector<int> &prices) {
    int res = 0;
    std::stack<int> st;
    for (auto &&price : prices) {
      if (st.empty() || price > st.top()) {
        st.push(price);
      } else {
        auto up = st.top();
        st.pop();
        while (!st.empty()) {
          auto low = st.top();
          st.pop();
          res += up - low;
          up = low;
        }
        st.push(price);
      }
    }
    if (!st.empty()) {
      int up = st.top();
      int low = up;
      while (!st.empty()) {
        low = st.top();
        st.pop();
      }
      res += up - low;
    }
    return res;
  }
};

TEST(leetcode, 122) {
  std::vector<int> prices = {1, 2, 3, 4, 5};
  ASSERT_EQ(Solution().maxProfit(prices), 4);
}
