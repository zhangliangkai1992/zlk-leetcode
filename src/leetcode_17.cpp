/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-04-23 00:10
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string &digits) {
    if (digits.empty()) {
      return {};
    }
    std::vector<std::string> digToChar = {"",    "",    "abc",  "def", "ghi",
                                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> res = {""};
    for (auto &&c : digits) {
      decltype(res) cp;
      cp.swap(res);
      for (const auto &s : cp) {
        for (auto &&ch : digToChar[c - '0']) {
          res.emplace_back(s + ch);
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 17) {
  auto digits = "23";
  auto res = Solution().letterCombinations(digits);
  decltype(res) expect = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  AssertVector(res, expect);
}
