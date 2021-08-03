/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-03 00:16
 */

#include <gtest/gtest.h>

class Solution {
  std::set<int64_t> all = {1};
  int genNext(const std::vector<int>& nums) {
    auto current = *all.begin();
    all.erase(all.begin());
    for (auto&& n : nums) {
      all.insert(current * n);
    }
    return current;
  }

 public:
  int nthSuperUglyNumber(int n, const std::vector<int>& nums) {
    for (int i = 1; i < n; ++i) {
      genNext(nums);
    }
    return genNext(nums);
  }
};

TEST(leetcode313, 1) {
  std::vector<int> nums = {2, 7, 13, 19};
  int n = 12;
  int expect = 32;
  ASSERT_EQ(Solution().nthSuperUglyNumber(n, nums), expect);
}
