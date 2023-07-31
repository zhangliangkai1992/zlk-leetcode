/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-31 21:36
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int jump(const std::vector<int> &nums) {
    auto sz = nums.size();
    std::vector<int> steps(sz, sz);
    steps[0] = 0;
    for (int i = 0; i < sz - 1; ++i) {
      int up = i + nums[i];
      for (int j = i + 1; j < sz && j <= up; ++j) {
        steps[j] = std::min(steps[j], steps[i] + 1);
      }
    }
    return steps.back();
  }
};

TEST(leetcode, 45) {
  const std::vector<int> nums = {2, 3, 1, 1, 4};
  int res = Solution().jump(nums);
  int expect = 2;
  ASSERT_EQ(expect, res);
}
