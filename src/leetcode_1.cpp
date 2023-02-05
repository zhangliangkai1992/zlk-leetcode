/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-05 10:27
 */
#include "include/leetcode_util.h"

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    int sz = nums.size();
    std::unordered_map<int, int> valueIndex;
    for (int i = 0; i < sz; ++i) {
      auto it = valueIndex.find(target - nums[i]);
      if (it != valueIndex.end()) {
        return {i, it->second};
      }
      valueIndex[nums[i]] = i;
    }
    return {-1, -1};
  }
};

TEST(leetcode, 1) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  std::vector<int> expect = {2, 1};
  auto res = Solution().twoSum(nums, target);
  AssertVector(expect, res);
}
