/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-01 09:50
 */

#include <include/leetcode_util.h>

class Solution {
  const std::unordered_map<char, int> kRomanToInt = {
      {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}};

public:
  int romanToInt(const std::string &s) {
    int last = 0;
    int res = 0;
    for (auto &&c : s) {
      auto v = kRomanToInt.find(c)->second;
      if (v > last) {
        res += v - 2 * last;
      } else {
        res += v;
      }
      last = v;
    }
    return res;
  }
};

TEST(leetcode, 13) {

  std::string s = "MMMCMXCIX";
  int expect = 3999;
  ASSERT_EQ(Solution().romanToInt(s), expect);
}
