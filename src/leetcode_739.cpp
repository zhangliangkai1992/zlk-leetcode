
/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-03 22:38
 */

#include <gtest/gtest.h>

#include <stack>
class Solution {
 public:
  std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    auto size = temperatures.size();
    std::vector<int> res(size, 0);
    // 单调递减栈
    std::stack<int> st;
    for (int i = 0; i < size; ++i) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        auto index = st.top();
        res[index] = i - index;
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
TEST(leetcode_739, 1) {
  Solution s;
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> res = {1, 1, 4, 2, 1, 1, 0, 0};
  auto cal = s.dailyTemperatures(temperatures);
  EXPECT_EQ(res.size(), cal.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], cal[i]);
  }
}
