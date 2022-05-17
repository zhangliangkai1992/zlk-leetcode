/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-05-17 20:58
 */

#include <gtest/gtest.h>
class Solution {
 public:
  int removeDuplicates(std::vector<int> *pnums) {
    const int kRepeateTime = 2;
    auto &&nums = *pnums;
    if (nums.empty()) {
      return 0;
    }
    int sz = nums.size();
    int count = 1;
    int index = 0;
    for (int i = 1; i < sz; ++i) {
      if (nums[index] != nums[i]) {
        int delta = std::min(count, kRepeateTime);
        index += delta;
        nums[index] = nums[i];
        count = 1;
        continue;
      }
      if (count < kRepeateTime) {
        nums[index + count] = nums[i];
      }
      ++count;
    }
    return index + std::min(count, kRepeateTime);
  }
};

TEST(leetcode, 80) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  std::vector<int> result = {1, 1, 2, 2, 3};
  int sz = result.size();
  ASSERT_EQ(Solution().removeDuplicates(&nums), sz);
  for (int i = 0; i < sz; ++i) {
    ASSERT_EQ(nums[i], result[i]);
  }
}
