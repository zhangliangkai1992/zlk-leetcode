/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/21 21:17
 */

#include <gtest/gtest.h>

class Solution {
public:
    int romanToInt(const std::string &s) {
        int sum = 0;
        std::unordered_map<std::string, int> roman_to_int = {
                {"I",  1},
                {"IV", 4},
                {"V",  5},
                {"IX", 9},
                {"X",  10},
                {"XL", 40},
                {"L",  50},
                {"XC", 90},
                {"C",  100},
                {"CD", 400},
                {"D",  500},
                {"CM", 900},
                {"M",  1000}
        };
        for (int i = 0; i < s.size();) {
            auto sub = s.substr(i, 2);
            if (roman_to_int.find(sub) != roman_to_int.end()) {
                sum += roman_to_int[sub];
                i += 2;
            } else {
                sum += roman_to_int[s.substr(i, 1)];
                i += 1;
            }
        }
        return sum;
    }
};

TEST(leetcode, 13) {
    std::string s = "MCMXCIV";
    int expect = 1994;
    ASSERT_EQ(expect, Solution().romanToInt(s));
}