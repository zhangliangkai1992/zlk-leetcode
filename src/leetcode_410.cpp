/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-14 22:43
 */

#include <gtest/gtest.h>

#include <numeric>

class Solution {
  // 判断nums划分成m块，每块和不超过bound
  bool valid(const std::vector<int>& nums, int m, int bound) {
    int current = 0;
    int count = 1;
    for (auto&& n : nums) {
      current += n;
      if (current > bound) {
        current = n;
        ++count;
        if (count > m) {
          return false;
        }
      }
    }
    return true;
  }

 public:
  int splitArray(const std::vector<int>& nums, int m) {
    // 二分查找范围在[max,sum]之间
    int low = *std::max_element(nums.begin(), nums.end());
    int up = std::accumulate(nums.begin(), nums.end(), 0);
    if (m == 1) return up;
    while (low <= up) {
      auto mid = (low + up) / 2;
      if (valid(nums, m, mid)) {
        up = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

TEST(leetcode410, 1) {
  std::vector<int> nums = {7, 2, 5, 10, 8};
  int m = 2;
  int expect = 18;
  ASSERT_EQ(Solution().splitArray(nums, m), expect);
}
