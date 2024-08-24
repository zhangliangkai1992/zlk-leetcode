/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/24 18:17
 */

#include <gtest/gtest.h>
#include <stack>

class Solution {
public:
    int calculate(const std::string &s) {
        auto sz = s.size();
        std::stack<long> st;
        long res = 0;
        long numbers = 0;
        int sign = 1;
        for (auto &&c: s) {
            if (c >= '0' && c <= '9') {
                numbers = 10 * numbers + c - '0';
            } else if (c == '+') {
                res += sign * numbers;
                numbers = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * numbers;
                numbers = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * numbers;
                numbers = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += sign * numbers;
        return res;
    }
};

TEST(leetcode, 224) {
    const std::string &expression = "(1+(4+5+2)-3)+(6+8)";
    int expect = 23;
    ASSERT_EQ(Solution().calculate(expression), expect);
}

