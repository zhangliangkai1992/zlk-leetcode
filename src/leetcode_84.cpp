/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-04 20:24
 */
#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  int largestRectangleArea(const std::vector<int> &heights) {
    std::stack<int> st;
    auto cp = heights;
    cp.push_back(0);
    int res = 0;
    for (int i = 0; i < cp.size();) {
      if (st.empty() || cp[i] > cp[st.top()]) {
        st.push(i++);
      } else {
        auto index = st.top();
        st.pop();
        res = std::max(res, cp[index] * (st.empty() ? i : (i - st.top() - 1)));
      }
    }
    return res;
  }
};

TEST(leetcode, 84) {
  std::vector<int> heights = {2, 1, 5, 6, 2, 3};
  int expect = 10;
  ASSERT_EQ(expect, Solution().largestRectangleArea(heights));
}
