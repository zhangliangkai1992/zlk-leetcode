/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-20 23:54
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int firstMissingPositive(std::vector<int> *pnums) {
    auto &&nums = *pnums;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == i + 1 || nums[i] >= sz || nums[i] < 1) {
        continue;
      }
      while (nums[i] != i + 1 && nums[i] >= 1 && nums[i] < sz &&
             nums[nums[i] - 1] != nums[i]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return sz + 1;
  }
};

TEST(leetcode, 41) {
  std::vector<int> nums = {-1, 4, 2, 1, 9, 10};
  int expect = 3;
  ASSERT_EQ(Solution().firstMissingPositive(&nums), expect);
}
