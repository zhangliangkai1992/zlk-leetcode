/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-05 22:58
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int threeSumClosest(const std::vector<int>& nums, int target) {
    auto sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());
    int res = sortedNums[0] + sortedNums[1] + sortedNums[2];
    int sz = nums.size();
    for (int i = 0; i < sz - 2; ++i) {
      if (i > 0 && sortedNums[i] == sortedNums[i - 1]) continue;
      int low = i + 1;
      int high = sz - 1;
      while (low < high) {
        auto sum = sortedNums[i] + sortedNums[low] + sortedNums[high];
        if (sum == target) return target;
        if (std::abs(sum - target) < std::abs(res - target)) {
          res = sum;
        }
        if (sum > target) {
          --high;
        } else {
          ++low;
        }
      }
    }
    return res;
  }
};

TEST(leetcode16, 1) {
  std::vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  int expect = 2;
  ASSERT_EQ(Solution().threeSumClosest(nums, target), expect);
}
