/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-20 09:08
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::string countAndSay(int n) {
    std::string res = "1";
    for (int i = 1; i < n; ++i) {
      std::string next;
      char cur = res[0];
      int count = 0;
      for (int j = 0; j < res.size();) {
        while (j < res.size() && cur == res[j]) {
          ++count;
          ++j;
        }
        next += std::to_string(count) + cur;
        if (j < res.size()) {
          cur = res[j];
          count = 0;
        }
      }
      res = next;
    }
    return res;
  }
};

TEST(leetcode38, 1) {
  int n = 4;
  std::string expect = "1211";
  ASSERT_EQ(Solution().countAndSay(n), expect);
}
