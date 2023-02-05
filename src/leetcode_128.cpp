/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-05 10:09
 */
#include <gtest/gtest.h>

#include <unordered_map>

class Solution {
 public:
  int longestConsecutive(const std::vector<int> &nums) {
    std::unordered_map<int, bool> used;
    for (auto &&n : nums) {
      used[n] = false;
    }
    int res = 0;
    for (auto &&n : nums) {
      if (used[n]) {
        continue;
      }
      used[n] = true;
      int delta = 1;
      int len = 1;
      while (used.find(n + delta) != used.end()) {
        used[n + delta] = true;
        ++delta;
      }
      len += delta - 1;
      delta = 1;
      while (used.find(n - delta) != used.end()) {
        used[n - delta] = true;
        ++delta;
      }
      len += delta - 1;
      res = std::max(len, res);
    }
    return res;
  }
};

TEST(leetcode, 128) {
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int expect = 9;
  ASSERT_EQ(Solution().longestConsecutive(nums), expect);
}
