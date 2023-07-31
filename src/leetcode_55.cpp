/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-31 21:28
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  bool canJump(const std::vector<int> &nums) {
    int high = 0;
    int sz = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (i > high) {
        return false;
      }
      if (high >= sz - 1) {
        return true;
      }
      high = std::max(high, nums[i] + i);
    }
    return high >= sz - 1;
  }
};

TEST(leetcode, 55) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  ASSERT_TRUE(Solution().canJump(nums));
}
