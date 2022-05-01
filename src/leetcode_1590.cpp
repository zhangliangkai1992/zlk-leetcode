/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-11-27 13:02
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minSubarray(const std::vector<int> &nums, int p) {
    int remainder = 0;
    for (auto &&n : nums) {
      remainder = (remainder + n) % p;
    }
    std::unordered_map<int, int> remainderValueIndex = {{0, -1}};
    int current = 0;
    int sz = nums.size();
    int res = sz;
    for (int i = 0; i < sz; ++i) {
      current = (current + nums[i]) % p;
      remainderValueIndex[current] = i;
      // 需要(current - want) % p = remainder
      int want = (current + p - remainder) % p;
      if (remainderValueIndex.count(want)) {
        res = std::min(res, i - remainderValueIndex[want]);
      }
    }
    return res < sz ? res : -1;
  }
};

TEST(leeetcode, 1590) { ASSERT_EQ(Solution().minSubarray({6, 3, 5, 2}, 9), 2); }

TEST(leeetcode, 1590_2) { ASSERT_EQ(Solution().minSubarray({4, 4, 2}, 7), -1); }
