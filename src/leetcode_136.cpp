/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 00:52
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int singleNumber(const std::vector<int> &nums) {
    int res = 0;
    for (auto &&n : nums) {
      res = res ^ n;
    }
    return res;
  }
};

TEST(leetcode, 136) {
  std::vector<int> nums = {4, 1, 2, 1, 2};
  auto res = Solution().singleNumber(nums);
  ASSERT_EQ(res, 4);
}
