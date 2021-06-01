/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-05-25 01:02
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::set<int64_t> nums;
    // 流的思想，取一个数最多放3个数，最少放一个数
    nums.insert(1);
    int64_t res = 0;
    while (n > 0) {
      res = *nums.begin();
      --n;
      nums.insert(res * 2);
      nums.insert(res * 3);
      nums.insert(res * 5);
      nums.erase(nums.begin());
    }
    return static_cast<int>(res);
  }
};

TEST(leetcode_264, 1) {
  Solution s;
  EXPECT_EQ(s.nthUglyNumber(1), 1);
  EXPECT_EQ(s.nthUglyNumber(10), 12);
  EXPECT_EQ(s.nthUglyNumber(1407), 536870912);
}
