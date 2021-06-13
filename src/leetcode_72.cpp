/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-14 00:20
 */

#include <gtest/gtest.h>

// Hard
class Solution {
 public:
  int minDistance(const std::string& s1, const std::string& s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    std::vector<std::vector<int>> res(len1 + 1, std::vector<int>(len2 + 1, 0));
    // 状态转移方程
    // 当前s1[i]与s2[j]比较
    // case 1: s1[i] == s2[j] ===>
    // res[i+1][j+1] =min(res[i][j],res[i][j+1]+1,res[i+1][j]+1)
    // case 2: s1[i] != s2[j] ===>
    // res[i+1][j+1] = min(res[i][j+1],res[i+1][j],res[i][j])+1
    for (int i = 0; i < res.size(); ++i) {
      res[i][0] = i;
    }
    for (int j = 0; j < res[0].size(); ++j) {
      res[0][j] = j;
    }
    for (int i = 0; i < len1; ++i) {
      for (int j = 0; j < len2; ++j) {
        auto m = std::min(res[i][j + 1], res[i + 1][j]);
        if (s1[i] == s2[j]) {
          res[i + 1][j + 1] = std::min(res[i][j], m + 1);
        } else {
          res[i + 1][j + 1] = std::min(res[i][j], m) + 1;
        }
      }
    }
    return *res.rbegin()->rbegin();
  }
};

TEST(leetcode_72, 1) {
  Solution s;
  EXPECT_EQ(s.minDistance("horse", "ros"), 3);
  EXPECT_EQ(s.minDistance("intention", "execution"), 5);
}
