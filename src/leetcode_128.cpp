/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-26 22:37
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int longestConsecutive(const std::vector<int>& nums) {
    std::set<int> all;
    for (auto&& n : nums) {
      all.insert(n);
    }
    int res = 0;
    auto it = all.begin();
    while (it != all.end()) {
      int start = *it;
      int cur = *it;
      while (it != all.end() && *it == cur) {
        ++it;
        ++cur;
      }
      res = std::max(res, cur - start);
    }
    return res;
  }
};

TEST(leetcode_128, 1) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  EXPECT_EQ(Solution().longestConsecutive(nums), 4);
}
