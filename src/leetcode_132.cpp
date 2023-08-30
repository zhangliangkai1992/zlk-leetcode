/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-08-30 20:42
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int minCut(const std::string &s) {
    auto sz = s.size();
    std::vector<std::vector<bool>> palindrome(sz, std::vector<bool>(sz, false));
    std::vector<int> res(sz + 1, 0);
    for (int i = 0; i <= sz; ++i) {
      res[i] = sz - 1 - i;
    }
    for (int i = sz - 1; i >= 0; --i) {
      for (int j = i; j < sz; ++j) {
        if (s[i] == s[j] && (j - i < 2 || palindrome[i + 1][j - 1])) {
          palindrome[i][j] = true;
          res[i] = std::min(res[i], res[j + 1] + 1);
        }
      }
    }
    return res[0];
  }
};

TEST(leetcode, 132) {
  auto s = "aab";
  ASSERT_EQ(Solution().minCut(s), 1);
}
