/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 17:14
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  int leastInterval(const std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> charCount;
    int maxCount = 0;
    int maxEleCount = 1;
    for (auto&& c : tasks) {
      ++charCount[c];
      if (charCount[c] == maxCount) {
        ++maxEleCount;
      } else if (charCount[c] > maxCount) {
        maxCount = charCount[c];
        maxEleCount = 1;
      }
    }
    return std::max(static_cast<int>(tasks.size()),
                    (maxCount - 1) * (n + 1) + maxEleCount);
  }
};
std::vector<char> stringToVec(const std::string& s) {
  std::vector<char> vec;
  for (auto&& c : s) {
    vec.push_back(c);
  }
  return vec;
}
TEST(leetcode_621, 1) {
  std::string s = "AAABBB";
  EXPECT_EQ(Solution().leastInterval(stringToVec(s), 2), 8);
  s = "AB";
  EXPECT_EQ(Solution().leastInterval(stringToVec(s), 2), 2);
}
