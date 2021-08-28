/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-28 17:56
 */

#include <gtest/gtest.h>

class Solution {
  void dfs(std::vector<std::string> *pBoard, int row,
           std::vector<std::vector<std::string>> *pRes, int n,
           std::vector<int> *pQPos) {
    auto &&board = *pBoard;
    if (row >= n) {
      pRes->push_back(board);
      return;
    }
    std::vector<bool> exist(n, false);
    auto &&qPos = *pQPos;
    for (int i = 0; i < n; ++i) {
      auto j = qPos[i];
      if (j != -1) {
        exist[j] = true;
        auto lineRight = i + j - row;
        if (lineRight >= 0 && lineRight < n) {
          exist[lineRight] = true;
        }
        auto lineLeft = row - (i - j);
        if (lineLeft >= 0 && lineLeft < n) {
          exist[lineLeft] = true;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (!exist[j]) {
        board[row][j] = 'Q';
        qPos[row] = j;
        dfs(pBoard, row + 1, pRes, n, pQPos);
        board[row][j] = '.';
        qPos[row] = -1;
      }
    }
  }

 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<int> qPos(n, -1);
    dfs(&board, 0, &res, n, &qPos);
    return res;
  }
};

TEST(leetcod51, 1) {
  int n = 4;
  auto res = Solution().solveNQueens(n);
  decltype(res) expect = {{".Q..", "...Q", "Q...", "..Q."},
                          {"..Q.", "Q...", "...Q", ".Q.."}};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
}
