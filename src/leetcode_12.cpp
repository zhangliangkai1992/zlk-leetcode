/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-01 09:34
 */

#include <include/leetcode_util.h>

class Solution {
  const std::map<int, std::string> kIntegerMap = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

 public:
  std::string intToRoman(int n) {
    auto it = kIntegerMap.rbegin();
    std::string res;
    while (n || it != kIntegerMap.rend()) {
      if (n >= it->first) {
        res += it->second;
        n -= it->first;
      } else {
        ++it;
      }
    }
    return res;
  }
};

TEST(leetcode, 12) {
  int n = 3999;
  auto res = Solution().intToRoman(n);
  decltype(res) expect = "MMMCMXCIX";
  ASSERT_EQ(res, expect);
}
