/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 08:22
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int trap(const std::vector<int> &height) {
    auto sz = height.size();
    int res = 0;
    int leftPos = 0;
    int rightPos = sz - 1;
    for (int i = 0; i < sz; ++i) {
      if (height[i] > height[leftPos]) {
        leftPos = i;
      }
      if (height[sz - 1 - i] > height[rightPos]) {
        rightPos = sz - 1 - i;
      }
    }
    int left = 0;
    int current = height[left];
    for (int i = 1; i < leftPos; ++i) {
      if (height[i] > current) {
        current = height[i];
      } else {
        res += current - height[i];
      }
    }
    int right = sz - 1;
    current = height[right];
    for (int i = right - 1; i > rightPos; --i) {
      if (height[i] > current) {
        current = height[i];
      } else {
        res += current - height[i];
      }
    }
    for (int i = leftPos + 1; i < rightPos; ++i) {
      res += height[leftPos] - height[i];
    }
    return res;
  }
};

TEST(leetcode, 42) {
  std::vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int expect = 6;
  ASSERT_EQ(Solution().trap(nums), expect);
}
