/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-08-25 09:40
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int hIndex(const std::vector<int> &citations) {
    int low = 0;
    const int sz = citations.size();
    int high = sz - 1;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      if (citations[mid] == sz - mid) {
        return citations[mid];
      } else if (citations[mid] > sz - mid) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return sz - 1 - high;
  }
};

TEST(leetcode, 275) {
  std::vector<int> nums = {0, 1, 3, 5, 6};
  int res = 3;
  ASSERT_EQ(Solution().hIndex(nums), res);
  ASSERT_EQ(Solution().hIndex({1, 2, 100}), 2);
}