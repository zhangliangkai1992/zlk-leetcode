/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 09:14
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<int> plusOne(const std::vector<int> &digit) {
    std::vector<int> res;
    int carry = 1;
    for (auto it = digit.rbegin(); it != digit.rend(); ++it) {
      int sum = carry + *it;
      res.push_back(sum % 10);
      carry = sum / 10;
    }
    if (carry) {
      res.push_back(carry);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

TEST(leetcode, 66) {
  std::vector<int> digit = {4, 3, 2, 1};
  auto res = Solution().plusOne(digit);
  decltype(res) expect = {4, 3, 2, 2};
  AssertVector(res, expect);
}
