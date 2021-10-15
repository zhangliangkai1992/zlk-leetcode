/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-10-15 15:09
 */

#include <gtest/gtest.h>

class Solution {
  std::unordered_map<std::string, bool> cache_;
  std::string buildKey(const std::string &s1, const std::string &s2,
                       const std::string &s3) {
    if (s1 < s2) {
      return s1 + "-" + s2 + "-" + s3;
    }
    return s2 + "-" + s1 + "-" + s3;
  }
  bool inner(const std::string &s1, const std::string &s2,
             const std::string &s3) {
    if (s1.empty()) {
      return s2 == s3;
    }
    if (s2.empty()) {
      return s1 == s3;
    }
    auto key = buildKey(s1, s2, s3);
    if (cache_.count(key)) {
      return cache_[key];
    }
    return cache_[key] =
               s1[0] == s3[0] && inner(s1.substr(1), s2, s3.substr(1)) ||
               s2[0] == s3[0] && inner(s2.substr(1), s1, s3.substr(1));
  }

 public:
  bool isInterleave(const std::string &s1, const std::string &s2,
                    const std::string &s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    return inner(s1, s2, s3);
  }
};

TEST(leetcode, 97) {
  auto s1 = "aabcc";
  auto s2 = "dbbca";
  auto s3 = "aadbbbaccc";
  ASSERT_FALSE(Solution().isInterleave(s1, s2, s3));
}
