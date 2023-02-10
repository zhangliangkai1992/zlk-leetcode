/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-10 23:32
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

  bool onlyCheckExist() const {
    for (int i = 0; i < kBoard; ++i) {
      if (getBoard(i) != kAnyDigit && !validValue(i, getBoard(i))) {
        return false;
      }
    }
    return true;
  }

 public:
  bool isValidSudoku(std::vector<std::vector<char>> *pBoard) {
    pBoard_ = pBoard;
    // return dfsCheckBoard(0);
    return onlyCheckExist();
  }
};

TEST(leetcode, 36) {
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
  bool expect = true;
  ASSERT_EQ(Solution().isValidSudoku(&board), expect);
}

TEST(leetcode, 36_1) {
  std::vector<std::vector<char>> board = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  auto res = Solution().isValidSudoku(&board);
  bool expect = false;
  ASSERT_EQ(res, expect);
}

TEST(leetcode, 36_2) {
  std::vector<std::vector<char>> board = {
      {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
      {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
  auto res = Solution().isValidSudoku(&board);
  ASSERT_EQ(res, true);
}
