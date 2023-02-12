/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 09:27
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    std::vector<int> res;
    res.reserve(n);
    res.push_back(1);
    res.push_back(2);
    while (res.size() < n) {
      res.push_back(*res.rbegin() + *(res.rbegin() + 1));
    }
    return res.back();
  }
};

TEST(leetcode, 70) {
  int n = 2;
  int expect = 2;
  ASSERT_EQ(Solution().climbStairs(n), expect);
}
