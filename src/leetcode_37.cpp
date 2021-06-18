/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 00:29
 */
#include <gtest/gtest.h>

// hard
class Solution {
  inline int GetXByIndex(int index) { return index / 9; }
  inline int GetYByIndex(int index) { return index % 9; }
  int FindNext(const std::vector<std::vector<char>>& board, int index) {
    for (int i = index; i < 81; ++i) {
      if (board[GetXByIndex(i)][GetYByIndex(i)] == '.') return i;
    }
    return 81;
  }

  bool check(const std::vector<std::vector<char>>& board, int pos, char value) {
    int x = GetXByIndex(pos);
    int y = GetYByIndex(pos);
    for (int i = 0; i < 9; ++i) {
      if (i != x && board[i][y] == value) return false;
      if (i != y && board[x][i] == value) return false;
    }
    int lowX = x / 3 * 3;
    int lowY = y / 3 * 3;
    for (int i = lowX; i < lowX + 3; ++i) {
      for (int j = lowY; j < lowY + 3; ++j) {
        if (board[i][j] == value) return false;
      }
    }
    return true;
  }

  // 返回从index位置是否能解出答案
  bool dfs(std::vector<std::vector<char>>* pBoard, int index) {
    auto& board = *pBoard;
    int next = FindNext(board, index);
    if (next >= 81) return true;
    for (int i = 1; i <= 9; ++i) {
      char value = '0' + i;
      if (check(board, next, value)) {
        board[GetXByIndex(next)][GetYByIndex(next)] = value;
        if (dfs(pBoard, next)) return true;
        board[GetXByIndex(next)][GetYByIndex(next)] = '.';
      }
    }
    return false;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>>* pBoard) {
    auto& board = *pBoard;
    dfs(pBoard, 0);
  }
};

TEST(leetcode_37, 1) {
  std::vector<std::vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  decltype(board) expect = {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
  Solution s;
  s.solveSudoku(&board);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      EXPECT_EQ(board[i][j], expect[i][j]);
    }
  }
}
