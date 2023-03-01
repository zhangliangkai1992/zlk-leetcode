/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-01 09:18
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    std::string res;
    for (int i = 0; i < 200; ++i) {
      bool valid = false;
      char current = 0;
      for (auto &&s : strs) {
        if (s.size() <= i) {
          return res;
        }
        if (!valid) {
          valid = true;
          current = s[i];
        } else if (s[i] != current) {
          return res;
        }
      }
      res += current;
    }
    return res;
  }
};

TEST(leetcode, 14) {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  auto res = Solution().longestCommonPrefix(strs);
  decltype(res) expect = "fl";
  ASSERT_EQ(res, expect);
}
