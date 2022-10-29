/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 01:17
 */
#include <gtest/gtest.h>

#include <stack>

// hard
class Solution {
 public:
  int trap(const std::vector<int> &height) {
    int res = 0;
    auto sz = height.size();
    if (sz < 2) return res;
    std::stack<decltype(sz)> st;
    st.push(0);
    for (int i = 1; i < sz; ++i) {
      if (height[i] > height[st.top()]) {
        st.push(i);
      }
    }
    auto left = st.top();
    auto up = left;
    st.pop();
    while (!st.empty()) {
      auto low = st.top();
      st.pop();
      for (int i = low + 1; i < up; ++i) {
        res += height[low] - height[i];
      }
      up = low;
    }
    st.push(sz - 1);
    for (int i = sz - 2; i >= 0; --i) {
      if (height[i] > height[st.top()]) {
        st.push(i);
      }
    }
    auto right = st.top();
    up = right;
    st.pop();
    while (!st.empty()) {
      auto low = st.top();
      st.pop();
      for (int i = up + 1; i < low; ++i) {
        res += height[low] - height[i];
      }
      up = low;
    }

    for (decltype(sz) i = left + 1; i < right; ++i) {
      res += height[left] - height[i];
    }
    return res;
  }
};

TEST(leetcode_42, 1) {
  std::vector<int> height = {2, 0, 2};
  auto res = Solution().trap(height);
  EXPECT_EQ(res, 2);
}
