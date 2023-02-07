/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-07 09:22
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int> *pNums) {
    auto &&nums = *pNums;
    std::sort(nums.begin(), nums.end());
    auto sz = nums.size();
    std::vector<std::vector<int>> res;
    std::unordered_map<int, int> elePos;
    for (int i = 0; i < sz; ++i) {
      // 只保留最后一个
      elePos[nums[i]] = i;
    }
    for (int i = 0; i < sz - 1; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < sz; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        auto target = 0 - nums[i] - nums[j];
        auto it = elePos.find(target);
        if (it != elePos.end() && it->second > j) {
          res.push_back({nums[i], nums[j], target});
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 15) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, 4};
  auto res = Solution().threeSum(&nums);
  decltype(res) expect = {{-1, -1, 2}, {-1, 0, 1}};

  AssertMatrix(res, expect);
}

TEST(leetcode, 15_1) {
  std::vector<int> nums = {0, 0, 0, 0};
  auto res = Solution().threeSum(&nums);
  decltype(res) expect = {{0, 0, 0}};
  AssertMatrix(res, expect);
}
