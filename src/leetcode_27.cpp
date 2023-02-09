/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-09 09:18
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int removeElement(std::vector<int> *pNums, int value) {
    auto &&nums = *pNums;
    auto sz = nums.size();
    int last = sz - 1;
    while (last >= 0 && nums[last] == value) --last;
    for (int i = 0; i <= last; ++i) {
      if (nums[i] == value) {
        std::swap(nums[i], nums[last]);
        while (last >= i && nums[last] == value) --last;
      }
    }
    return last + 1;
  }
};

TEST(leetcode, 27) {
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  auto res = Solution().removeElement(&nums, 2);
  std::vector<int> afterNums = {0, 1, 4, 0, 3};
  ASSERT_EQ(res, afterNums.size());
  AssertSubVectorEqual(nums, res, afterNums);
}
