/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-29 00:25
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> res;
    for (auto&& n : nums) {
      if (res.empty() || n > res.back()) {
        res.push_back(n);
      } else {
        for (int i = res.size() - 1; i >= 0; --i) {
          if (i == 0 || res[i - 1] < n) {
            res[i] = std::min(res[i], n);
            break;
          }
        }
      }
    }
    return static_cast<int>(res.size());
  }
};
TEST(leetcode_300, 1) {
  std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  EXPECT_EQ(Solution().lengthOfLIS(nums), 4);
}
