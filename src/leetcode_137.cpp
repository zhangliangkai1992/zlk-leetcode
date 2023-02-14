/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 00:56
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int singleNumber(const std::vector<int> &nums) {
    constexpr auto len = 8 * sizeof(int);
    std::vector<int> bitCount(len, 0);
    for (auto &&n : nums) {
      for (int i = 0; i < len; ++i) {
        int v = 1 << i;
        if ((v & n) != 0) {
          ++bitCount[i];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < len; ++i) {
      if (bitCount[i] % 3 != 0) {
        res = res | (1 << i);
      }
    }
    return res;
  }
};

TEST(leetcode, 137) {
  std::vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
  auto res = Solution().singleNumber(nums);
  ASSERT_EQ(res, 99);
}
