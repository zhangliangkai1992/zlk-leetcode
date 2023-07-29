/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 16:44
 */

#include <include/leetcode_util.h>

class Solution {
  std::vector<std::string> board_;
  std::vector<decltype(board_)> res_;
  void dfs(int row, int n) {
    if (row == n) {
      res_.push_back(board_);
      return;
    }
    for (int j = 0; j < n; ++j) {
      if (check(row, j, n)) {
        board_[row][j] = 'Q';
        dfs(row + 1, n);
        board_[row][j] = '.';
      }
    }
  }
  bool check(int row, int col, int n) {
    for (int i = 0; i < n; ++i) {
      if (i != row && board_[i][col] == 'Q' ||
          i != col && board_[row][i] == 'Q') {
        return false;
      }
      int j = i - row + col;
      if (j >= 0 && j < n && i != row && board_[i][j] == 'Q') {
        return false;
      }
    }
    int sum = row + col;
    for (int i = 0; i < sum && i < n; ++i) {
      if (i != row && (sum - i < n) && board_[i][sum - i] == 'Q') {
        return false;
      }
    }
    return true;
  }

 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    board_ = std::vector<std::string>(n, std::string(n, '.'));
    dfs(0, n);
    return res_;
  }
};

TEST(leetcode, 51) {
  int n = 4;
  auto res = Solution().solveNQueens(n);
  decltype(res) expect = {{".Q..", "...Q", "Q...", "..Q."},
                          {"..Q.", "Q...", "...Q", ".Q.."}};
  AssertMatrix(expect, res);
}
