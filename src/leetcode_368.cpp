/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-07 20:06
 */

#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<int> largestDivisibleSubset(const std::vector<int>& nums) {
    // LIS：把"小于"意义转换成"取模"
    auto sortNum = nums;
    std::sort(sortNum.begin(), sortNum.end());
    auto sz = nums.size();
    int maxCount = 0;
    int maxIndex = -1;
    // count[i],pre[i]表示最大长度为count[i]的前一个的索引为pre[i]
    std::vector<int> count(sz, 1);
    std::vector<int> preIndex(sz, -1);
    for (int i = 0; i < sz; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (sortNum[i] % sortNum[j] == 0) {
          if (1 + count[j] > count[i]) {
            count[i] = 1 + count[j];
            preIndex[i] = j;
          }
        }
      }
      if (count[i] > maxCount) {
        maxCount = count[i];
        maxIndex = i;
      }
    }
    std::vector<int> res;
    while (maxIndex != -1) {
      res.push_back(sortNum[maxIndex]);
      maxIndex = preIndex[maxIndex];
    }
    return res;
  }
};

TEST(leetcode368, 1) {
  std::vector<int> nums = {1, 2, 3};
  auto res = Solution().largestDivisibleSubset(nums);
  decltype(res) expect = {2, 1};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
TEST(leetcode368, 2) {
  std::vector<int> nums = {4, 8, 3, 16};
  auto res = Solution().largestDivisibleSubset(nums);
  decltype(res) expect = {16, 8, 4};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
