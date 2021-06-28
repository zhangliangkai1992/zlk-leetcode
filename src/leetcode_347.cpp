/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-28 23:12
 */
#include <gtest/gtest.h>

class Solution {
 public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::map<int, int> numCount;
    for (auto&& n : nums) {
      ++numCount[n];
    }
    std::map<int, std::vector<int>> freqNums;
    for (auto&& p : numCount) {
      freqNums[p.second].push_back(p.first);
    }
    std::vector<int> res;
    int left = k;
    while (left > 0) {
      auto vec = freqNums.rbegin()->second;
      left -= vec.size();
      res.insert(res.end(), vec.begin(), vec.end());
      freqNums.erase(freqNums.rbegin()->first);
    }
    return res;
  }
};

TEST(leetcode_347, 1) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  decltype(nums) expect = {1, 2};
  auto res = Solution().topKFrequent(nums, 2);
  EXPECT_EQ(expect.size(), res.size());
  for (int i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expect[i]);
  }
}
