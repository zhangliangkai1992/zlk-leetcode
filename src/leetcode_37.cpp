/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-11 01:05
 */
#include <include/leetcode_util.h>

class Solution {
  constexpr static int kSide = 3;
  constexpr static int kSquare = kSide * kSide;
  constexpr static int kBoard = kSquare * kSquare;
  constexpr static char kAnyDigit = '.';
  inline int getRow(int pos) const { return pos / kSquare; }
  inline int getCol(int pos) const { return pos % kSquare; }
  inline void setBoard(int pos, char c) {
    (*pBoard_)[getRow(pos)][getCol(pos)] = c;
  }
  inline char valueToChar(int v) const { return v + '0'; }
  inline char getBoard(int pos) const {
    return getBoard(getRow(pos), getCol(pos));
  }
  inline char getBoard(int row, int col) const { return (*pBoard_)[row][col]; }
  int checkNextPos(int pos) {
    for (int i = pos; i < kBoard; ++i) {
      if (getBoard(i) == kAnyDigit) {
        return i;
      }
    }
    return kBoard;
  }
  std::vector<std::vector<char>> *pBoard_;

  bool validValue(int pos, char value) const {
    auto row = getRow(pos);
    auto col = getCol(pos);

    for (int i = 0; i < kSquare; ++i) {
      if (i != row && getBoard(i, col) == value) {
        return false;
      }
      if (i != col && getBoard(row, i) == value) {
        return false;
      }
    }
    int lowRow = row / kSide * kSide;
    int lowCol = col / kSide * kSide;
    for (int i = lowRow; i < lowRow + kSide; ++i) {
      for (int j = lowCol; j < lowCol + kSide; ++j) {
        if ((i != row || j != col) && getBoard(i, j) == value) {
          return false;
        }
      }
    }
    return true;
  }
  bool dfsCheckBoard(int pos) {
    auto nextPos = checkNextPos(pos);
    if (nextPos >= kBoard) {
      return true;
    }
    for (int i = 1; i <= kSquare; ++i) {
      if (validValue(nextPos, valueToChar(i))) {
        setBoard(nextPos, valueToChar(i));
        if (dfsCheckBoard(nextPos + 1)) {
          return true;
        }
      }
    }
    setBoard(nextPos, kAnyDigit);
    return false;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>> *pBoard) {
    pBoard_ = pBoard;
    dfsCheckBoard(0);
  }
};

TEST(leetcode, 37) {
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
  Solution().solveSudoku(&board);
  AssertMatrix(board, expect);
}
