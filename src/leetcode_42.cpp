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
  int trap(const std::vector<int>& height) {
    int sz = height.size();
    if (sz == 0) return 0;
    std::stack<int> left;
    for (int i = 0; i < sz; ++i) {
      if (left.empty() || height[i] > height[left.top()]) {
        left.push(i);
      }
    }
    std::stack<int> right;
    for (int j = sz - 1; j >= 0; --j) {
      if (right.empty() || height[j] > height[right.top()]) {
        right.push(j);
      }
    }
    int res = 0;
    for (int i = left.top(); i < right.top(); ++i) {
      res += (height[left.top()] - height[i]);
    }
    int index = left.top();
    left.pop();
    while (!left.empty()) {
      int top = left.top();
      for (int i = top + 1; i < index; ++i) {
        res += (height[top] - height[i]);
      }
      index = top;
      left.pop();
    }
    index = right.top();
    right.pop();
    while (!right.empty()) {
      int top = right.top();
      for (int i = index + 1; i < top; ++i) {
        res += (height[top] - height[i]);
      }
      index = top;
      right.pop();
    }
    return res;
  }
};

TEST(leetcode_42, 1) {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto res = Solution().trap(height);
  EXPECT_EQ(res, 6);
}
