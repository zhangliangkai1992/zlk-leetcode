/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-27 22:54
 */

#include <gtest/gtest.h>

#include <unordered_set>

class Solution {
 public:
  bool canReach(const std::string &s, int minJump, int maxJump) {
    auto sz = s.size();
    std::vector<bool> res(sz, false);
    res[0] = true;
    // pre表示之前的位置可以到的次数
    int pre = 0;
    for (int i = 1; i < sz; ++i) {
      if (i >= minJump && res[i - minJump]) {
        ++pre;
      }
      if (i > maxJump && res[i - maxJump - 1]) {
        --pre;
      }
      res[i] = pre > 0 && '0' == s[i];
    }
    return res.back();
  }
};

TEST(leetcode1871, 1) {
  auto s = "011010";
  int minJump = 2;
  int maxJump = 3;
  bool expect = true;
  ASSERT_EQ(Solution().canReach(s, minJump, maxJump), expect);
}
