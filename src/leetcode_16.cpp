/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-08 09:27
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int threeSumClosest(std::vector<int> *pNums, int target) {
    auto &&nums = *pNums;
    auto sz = nums.size();
    int res = nums[0] + nums[1] + nums[2];
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < sz - 2; ++i) {
      int low = i + 1;
      int high = sz - 1;
      while (low < high) {
        int sum = nums[i] + nums[low] + nums[high];
        if (std::abs(sum - target) < std::abs(res - target)) {
          res = sum;
        }
        if (sum > target) {
          --high;
        } else if (sum < target) {
          ++low;
        } else {
          return target;
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 16) {
  std::vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  int expect = 2;
  ASSERT_EQ(Solution().threeSumClosest(&nums, target), expect);
}
