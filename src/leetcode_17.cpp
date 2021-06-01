/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-01 23:55
 */
#include <gtest/gtest.h>

class Solution {
  std::map<char, std::vector<char>> maps = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
  void dfs(std::string* cur, const int i, std::vector<std::string>* res) {
    if (i >= cur->size()) {
      res->push_back(*cur);
      return;
    }
    auto cur_char = (*cur)[i];
    auto&& v = maps[cur_char];
    for (auto c : v) {
      (*cur)[i] = c;
      dfs(cur, i + 1, res);
    }
    (*cur)[i] = cur_char;
  }

 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) return {};
    auto cur = digits;
    std::vector<std::string> res;
    dfs(&cur, 0, &res);
    return res;
  }
};

TEST(leetcode_17, 1) {
  Solution s;
  auto letters = s.letterCombinations("23");
  EXPECT_EQ(9, letters.size());
  EXPECT_EQ(letters[0], "ad");
  EXPECT_EQ(letters[1], "ae");
  EXPECT_EQ(letters[2], "af");
  EXPECT_EQ(letters[3], "bd");
  EXPECT_EQ(letters[4], "be");
  EXPECT_EQ(letters[5], "bf");
  EXPECT_EQ(letters[6], "cd");
  EXPECT_EQ(letters[7], "ce");
  EXPECT_EQ(letters[8], "cf");
}

TEST(leetcode_17, 2) {
  Solution s;
  auto empty = s.letterCombinations("");
  EXPECT_EQ(0, empty.size());
}
