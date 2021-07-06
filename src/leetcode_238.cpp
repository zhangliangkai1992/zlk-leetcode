/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-06 23:13
 */
#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int zero = 0;
    int product = 1;
    auto sz = nums.size();
    decltype(sz) index = -1;
    for (decltype(sz) i = 0; i < sz; ++i) {
      if (nums[i] == 0) {
        ++zero;
        index = i;
      } else {
        product *= nums[i];
      }
    }
    std::vector<int> res(nums.size(), 0);
    if (zero > 1) {
      return res;
    }
    if (zero == 1) {
      res[index] = product;
      return res;
    }
    for (decltype(sz) i = 0; i < sz; ++i) {
      res[i] = product / nums[i];
    }
    return res;
  }
};

TEST(leetcode238, 1) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto res = Solution().productExceptSelf(nums);
  decltype(res) expect = {24, 12, 8, 6};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
