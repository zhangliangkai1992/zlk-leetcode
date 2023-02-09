/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-09 09:39
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  void nextPermutation(std::vector<int> *pNums) {
    auto &&s = *pNums;
    auto sz = s.size();
    int partIndex = sz - 2;
    // step 1: 从右到左找到第一个不是递增的位置
    while (partIndex >= 0 && s[partIndex] >= s[partIndex + 1]) --partIndex;
    if (partIndex < 0) {
      std::reverse(s.begin(), s.end());
      return;
    }
    // step 2: 从右到左找到第一个比它大的
    int highIndex = sz - 1;
    while (s[partIndex] >= s[highIndex]) --highIndex;
    // step 3: 交换
    std::swap(s[partIndex], s[highIndex]);
    // step 4: partIndex后面的reverse
    std::reverse(s.begin() + partIndex + 1, s.end());
  }
};

TEST(leetcode, 31) {
  std::vector<int> nums = {1, 1, 5};
  std::vector<int> expect = {1, 5, 1};
  Solution().nextPermutation(&nums);
  AssertVector(nums, expect);
}
