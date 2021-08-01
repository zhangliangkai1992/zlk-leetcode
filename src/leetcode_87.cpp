/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-02 00:02
 */

#include <gtest/gtest.h>

class Solution {
  std::unordered_map<std::string, bool> cache;

 public:
  bool isScramble(const std::string& s1, const std::string& s2) {
    int sz = s1.size();
    if (sz == 0) return true;
    if (sz == 1) return s1 == s2;
    auto key = s1 + s2;
    if (cache.find(key) != cache.end()) {
      return cache[key];
    }
    for (int i = 1; i < sz; ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
              isScramble(s1.substr(i, sz - i), s2.substr(i, sz - i)) ||
          isScramble(s1.substr(0, i), s2.substr(sz - i, i)) &&
              isScramble(s1.substr(i, sz - i), s2.substr(0, sz - i))) {
        cache[key] = true;
        break;
      }
    }
    return cache[key];
  }
};

TEST(leetcode87, 1) {
  ASSERT_EQ(Solution().isScramble("great", "rgeat"), true);
}
