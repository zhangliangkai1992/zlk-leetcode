
/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-01 23:05
 */
#include <gtest/gtest.h>

#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(const std::vector<int>& all) {
    auto nums = all;
    std::sort(nums.begin(), nums.end());
    int sz = nums.size();
    std::vector<std::vector<int>> res;
    for (int i = 0; i < sz - 2; ++i) {
      if (i == 0 || (nums[i] != nums[i - 1])) {
        int j = i + 1;
        int k = sz - 1;
        while (j < k) {
          auto sum = nums[i] + nums[j] + nums[k];
          if (sum == 0) {
            res.push_back({nums[i], nums[j], nums[k]});
            while (j < k && nums[j] == nums[j + 1]) ++j;
            while (j < k && nums[k] == nums[k - 1]) --k;
            ++j;
            --k;
          } else if (sum < 0) {
            ++j;
          } else {
            --k;
          }
        }
      }
    }
    return res;
  }
};
TEST(leetcode_15, 1) {}
