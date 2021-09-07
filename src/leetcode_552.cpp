/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-07 22:10
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int checkRecord(int n) {
    // zeroA[i]表示有0个A且最后连续i个L
    std::vector<int> zeroA({1, 1, 0});
    std::vector<int> oneA({1, 0, 0});
    const int mod = 1e9 + 7;
    for (int i = 1; i < n; ++i) {
      decltype(zeroA) nextZeroA(3, 0);
      auto sumZeroMod = 0;
      for (auto &&k : zeroA) {
        sumZeroMod = (sumZeroMod + k) % mod;
      }
      // 只能加P
      nextZeroA[0] = sumZeroMod;
      // 只能加L
      nextZeroA[1] = zeroA[0];
      nextZeroA[2] = zeroA[1];
      decltype(zeroA) nextOneA(3, 0);

      // 末尾加A
      nextOneA[0] = sumZeroMod;
      // 末尾加P
      for (auto &&k : oneA) {
        nextOneA[0] = (nextOneA[0] + k) % mod;
      }
      // 末尾加L
      nextOneA[1] = oneA[0];
      nextOneA[2] = oneA[1];

      zeroA = nextZeroA;
      oneA = nextOneA;
    }
    int res = 0;
    for (auto &&k : zeroA) {
      res = (res + k) % mod;
    }
    for (auto &&k : oneA) {
      res = (res + k) % mod;
    }
    return res;
  }
};

TEST(leetcode, 552) {
  int n = 4;
  int expect = 43;
  ASSERT_EQ(Solution().checkRecord(n), expect);
}
