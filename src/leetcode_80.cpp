/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-01-31 23:32
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int removeDuplicates(std::vector<int> *pNum) {
    auto &&nums = *pNum;
    constexpr int kMaxRepeat = 2;
    auto sz = nums.size();
    if (sz <= kMaxRepeat) {
      return sz;
    }
    int current = nums[0];
    int currentCount = 1;
    int index = 0;
    for (int i = 1; i < sz; ++i) {
      if (nums[i] != current) {
        nums[++index] = nums[i];
        current = nums[i];
        currentCount = 1;
      } else {
        if (++currentCount <= kMaxRepeat) {
          nums[++index] = nums[i];
        }
      }
    }
    return index + 1;
  }
};

TEST(leetcode, 80) {
  std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  std::vector<int> expect = {0, 0, 1, 1, 2, 3, 3};

  ASSERT_EQ(expect.size(), Solution().removeDuplicates(&nums));
  for (int i = 0; i < expect.size(); ++i) {
    ASSERT_EQ(expect[i], nums[i]);
  }
}
