/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-23 22:29
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    int sz = nums.size();
    int up = 1 << sz;
    std::vector<std::vector<int>> res;
    res.reserve(up);
    for (int i = 0; i < up; ++i) {
      std::vector<int> row;
      for (int j = 0; j < sz; ++j) {
        if (i & (1 << j)) {
          row.push_back(nums[j]);
        }
      }
      res.push_back(row);
    }
    return res;
  }
};

TEST(leetcode, 78) {
  std::vector<int> nums = {1, 2, 3};
  auto res = Solution().subsets(nums);
  decltype(res) expect = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  AssertMatrix(expect, res);
}
