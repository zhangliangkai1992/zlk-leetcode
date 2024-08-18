/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/17 20:45
 */

#include <gtest/gtest.h>
#include <stack>

class Solution {
public:
    int evalRPN(const std::vector<std::string> &tokens) {
        std::stack<int> st;
        for (auto &&token: tokens) {
            if (token == "+") {
                auto v2 = st.top();
                st.pop();
                auto v1 = st.top();
                st.pop();
                st.push(v1 + v2);
            } else if (token == "-") {
                auto v2 = st.top();
                st.pop();
                auto v1 = st.top();
                st.pop();
                st.push(v1 - v2);
            } else if (token == "*") {
                auto v2 = st.top();
                st.pop();
                auto v1 = st.top();
                st.pop();
                st.push(v1 * v2);
            } else if (token == "/") {
                auto v2 = st.top();
                st.pop();
                auto v1 = st.top();
                st.pop();
                st.push(v1 / v2);
            } else {
                st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};


TEST(leetcode, 150) {
    std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int expect = 22;
    ASSERT_EQ(expect, Solution().evalRPN(tokens));
}