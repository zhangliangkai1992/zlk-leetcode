/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 00:19
 */

#include <gtest/gtest.h>

// medium
class Solution {
 public:
  std::vector<int> grayCode(int n) {
    if (n == 1) return {0, 1};
    auto last = grayCode(n - 1);
    std::vector<int> res(last);
    int mask = 1 << (n - 1);
    for (auto it = last.rbegin(); it != last.rend(); ++it) {
      res.push_back(mask | (*it));
    }
    return res;
  }
};

TEST(leetcode_89, 1) {
  Solution s;
  std::vector<int> expect = {0, 1};
  int n = 1;
  auto res = s.grayCode(n);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}

TEST(leetcode_89, 2) {
  Solution s;
  std::vector<int> expect = {0, 1, 3, 2};
  int n = 2;
  auto res = s.grayCode(n);
  EXPECT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}
