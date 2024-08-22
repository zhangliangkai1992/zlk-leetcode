/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/21 21:35
 */

#include <gtest/gtest.h>

class Solution {
public:
    std::string intToRoman(int n) {
        std::map<int, std::string> int_to_roman = {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"}
        };
        std::string roman;
        auto it = int_to_roman.rbegin();
        while (n) {
            int last = it->first;
            while (n >= last) {
                roman += it->second;
                n -= it->first;
            }
            ++it;
        }
        return roman;
    }
};

TEST(leetcode, 12) {
    int n = 3749;
    std::string roman = "MMMDCCXLIX";
    ASSERT_EQ(Solution().intToRoman(n), roman);
}