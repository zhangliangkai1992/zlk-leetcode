/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-08 09:39
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int> *pNums, int target) {
    auto &&nums = *pNums;
    int sz = nums.size();
    std::unordered_map<int64_t, int> elePos;
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < sz; ++i) {
      elePos[nums[i]] = i;
    }
    for (int i = 0; i < sz; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < sz; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        for (int k = j + 1; k < sz; ++k) {
          if (k > j + 1 && nums[k] == nums[k - 1]) {
            continue;
          }
          auto left = (int64_t)target - nums[i] - nums[j] - nums[k];
          auto it = elePos.find(left);
          if (it != elePos.end() && it->second > k) {
            res.push_back({nums[i], nums[j], nums[k], static_cast<int>(left)});
          }
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 18) {
  std::vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
  int target = -294967296;
  auto res = Solution().fourSum(&nums, target);
  decltype(res) expect = {};
  AssertMatrix(res, expect);
}
