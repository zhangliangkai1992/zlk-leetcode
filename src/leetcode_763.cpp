/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 22:48
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  std::vector<int> partitionLabels(const std::string& s) {
    std::unordered_map<char, int> charPos;
    for (int i = 0; i < s.size(); ++i) {
      charPos[s[i]] = i;
    }
    int low = 0;
    std::vector<int> res;
    while (low < s.size()) {
      for (int i = low + 1; i <= charPos[s[low]]; ++i) {
        charPos[s[low]] = std::max(charPos[s[low]], charPos[s[i]]);
      }
      res.push_back(charPos[s[low]] + 1 - low);
      low = charPos[s[low]] + 1;
    }
    return res;
  }
};

TEST(leetcode_763, 1) {
  std::string s = "ababcbacadefegdehijhklij";
  auto res = Solution().partitionLabels(s);
  std::vector<int> expect = {9, 7, 8};
  EXPECT_EQ(expect.size(), res.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}
