/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-03 21:58
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  // 1.找到最大的k使a[k] < a[k+1]，如果k不存在，则该排列是最后的排列
  // 2.找到最大的l使a[k] < a[l]
  // 3.交换a[k] a[l]
  // 4.反转a[k+1,l]
  std::vector<int> nextPermutation(const std::vector<int>& current) {
    std::vector<int> nums = current;

    int sz = nums.size();
    int k = -1;
    for (int i = sz - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        k = i;
        break;
      }
    }
    if (k == -1) {
      std::reverse(nums.begin(), nums.end());
      return nums;
    }
    int l = -1;
    for (int i = sz - 1; i > k; --i) {
      if (nums[k] < nums[i]) {
        l = i;
        break;
      }
    }
    std::swap(nums[k], nums[l]);
    std::reverse(nums.begin() + k + 1, nums.end());
    return nums;
  }
};

TEST(leetcode31, 1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> expect = {1, 3, 2};
  auto res = Solution().nextPermutation(nums);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
