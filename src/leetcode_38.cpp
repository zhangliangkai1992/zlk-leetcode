/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-01 23:42
 */

#include <include/leetcode_util.h>

class Solution {
  std::string trans(const std::string &s) {
    std::string res;
    int count = 1;
    char c = s[0];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == c) {
        ++count;
      } else {
        res += std::to_string(count) + c;
        count = 1;
        c = s[i];
      }
    }
    res += std::to_string(count) + c;
    return res;
  }

 public:
  std::string countAndSay(int n) {
    std::string res("1");
    while (n > 1) {
      --n;
      res = trans(res);
    }
    return res;
  }
};

TEST(leetcode, 38) {
  int n = 4;
  auto res = Solution().countAndSay(n);
  decltype(res) expect = "1211";
  ASSERT_EQ(res, expect);
}
