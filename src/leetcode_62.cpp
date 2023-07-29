/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 16:22
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> res(m, std::vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        res[i][j] = res[i - 1][j] + res[i][j - 1];
      }
    }
    return res[m - 1][n - 1];
  }
};

TEST(leetcode, 62) {
  int m = 3;
  int n = 7;
  int expect = 28;
  ASSERT_EQ(Solution().uniquePaths(m, n), expect);
}
