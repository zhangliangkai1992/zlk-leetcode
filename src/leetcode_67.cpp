/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-22 01:12
 */

#include <include/leetcode_util.h>
class Solution {
 public:
  std::string addBinary(const std::string &s1, const std::string &s2) {
    int p1 = s1.size() - 1;
    int p2 = s2.size() - 1;
    int carry = 0;
    std::string res;
    while (p1 >= 0 || p2 >= 0) {
      int b1 = p1 >= 0 ? s1[p1] - '0' : 0;
      int b2 = p2 >= 0 ? s2[p2] - '0' : 0;
      int sum = b1 + b2 + carry;
      res += ('0' + sum % 2);
      carry = sum / 2;
      --p1;
      --p2;
    }
    if (carry) {
      res += '1';
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

TEST(leetcode, 67) {
  const std::string s1 = "1010";
  const std::string s2 = "1011";
  auto res = Solution().addBinary(s1, s2);
  decltype(res) expect = "10101";
  ASSERT_EQ(expect, res);
}
