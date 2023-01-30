/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-01-30 09:47
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int removeDuplicates(std::vector<int> *pnums) {
    auto &&nums = *pnums;
    if (nums.empty()) {
      return 0;
    }
    int current = nums[0];
    int nextIdx = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (current != nums[i]) {
        current = nums[i];
        nums[nextIdx++] = current;
      }
    }
    return nextIdx;
  }
};

TEST(leetcode, 26) {
  std::vector<int> nums = {1, 1, 2};
  std::vector<int> expect = {1, 2};
  ASSERT_EQ(Solution().removeDuplicates(&nums), expect.size());
  for (int i = 0; i < expect.size(); ++i) {
    ASSERT_EQ(expect[i], nums[i]);
  }
}
