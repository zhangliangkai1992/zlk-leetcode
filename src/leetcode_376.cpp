/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-14 22:26
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int wiggleMaxLength(const std::vector<int>& nums) {
    auto sz = nums.size();
    // up[i]=k表示以第i个数为结尾的最长子串长度为k,且趋势为上升
    std::vector<int> up(sz, 0);
    std::vector<int> down(sz, 0);
    up[0] = down[0] = 1;
    for (int i = 1; i < sz; ++i) {
      if (nums[i] > nums[i - 1]) {
        up[i] = down[i - 1] + 1;
        down[i] = down[i - 1];
      } else if (nums[i] < nums[i - 1]) {
        down[i] = up[i - 1] + 1;
        up[i] = up[i - 1];
      } else {
        down[i] = down[i - 1];
        up[i] = up[i - 1];
      }
    }
    return std::max(up.back(), down.back());
  }
};

TEST(leetcode376, 1) {
  std::vector<int> nums = {1, 7, 4, 9, 2, 5};
  int expect = 6;
  ASSERT_EQ(Solution().wiggleMaxLength(nums), expect);
}
