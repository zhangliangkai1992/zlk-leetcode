/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-05-17 20:38
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int removeDuplicates(std::vector<int> *pnums) {
    auto &&nums = *pnums;
    if (nums.empty()) {
      return 0;
    }
    auto sz = nums.size();
    int index = 0;
    for (int i = 1; i < sz; ++i) {
      if (nums[index] != nums[i]) {
        nums[++index] = nums[i];
      }
    }
    return index + 1;
  }
};

TEST(leetcode, 26) {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::vector<int> result = {0, 1, 2, 3, 4};
  int n = result.size();
  ASSERT_EQ(Solution().removeDuplicates(&nums), n);
  for (int i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], nums[i]);
  }
}
