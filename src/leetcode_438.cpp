/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-04 00:02
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
  inline bool exist(const std::unordered_map<char, int>& charCount, char c) {
    return charCount.find(c) != charCount.end();
  }

 public:
  std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    std::unordered_map<char, int> charCount;
    for (auto&& c : p) {
      ++charCount[c];
    }
    const int sz = p.size();
    std::vector<int> res;
    int low = 0;
    int high = 0;
    int cur = charCount.size();
    while (high < s.size()) {
      if (exist(charCount, s[high])) {
        if (--charCount[s[high]] == 0) {
          --cur;
        }
      }
      ++high;
      while (cur == 0) {
        if (exist(charCount, s[low])) {
          if (++charCount[s[low]] > 0) {
            ++cur;
          }
        }
        if (high - low == sz) {
          res.push_back(low);
        }
        ++low;
      }
    }
    return res;
  }
};

TEST(leetcode438, 1) {
  auto res = Solution().findAnagrams("cbaebabacd", "abc");
  decltype(res) expect = {0, 6};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
