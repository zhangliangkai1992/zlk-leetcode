/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-24 22:47
 */
#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      const std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, int> word_index;
    for (auto&& str : strs) {
      auto word = str;
      std::sort(word.begin(), word.end());
      if (word_index.count(word) != 0) {
        res[word_index[word]].push_back(str);
      } else {
        word_index[word] = res.size();
        res.push_back({str});
      }
    }
    return res;
  }
};
TEST(leetcode_49, 1) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> expect = {
      {"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
  auto res = Solution().groupAnagrams(strs);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      EXPECT_EQ(res[i][j], expect[i][j]);
    }
  }
}
