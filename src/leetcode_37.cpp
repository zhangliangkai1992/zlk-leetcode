/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-19 00:29
 */
#include <gtest/gtest.h>

// hard
class Solution {
  const int BLOCK = 3;
  const int SZ = BLOCK * BLOCK;
  const int BOUND = SZ * SZ;
  const char ANY = '.';
  const int ONE = '1';

  inline int GetX(int index) { return index / SZ; }

  inline int GetY(int index) { return index % SZ; }

  int FindNext(const std::vector<std::vector<char>>& board, int start) {
    for (int i = start; i < BOUND; ++i) {
      if (board[GetX(i)][GetY(i)] == ANY) return i;
    }
    return BOUND;
  }

  bool Dfs(std::vector<std::vector<char>>* pBoard, int start) {
    auto& board = *pBoard;
    int next = FindNext(board, start);
    if (next >= BOUND) return true;
    std::vector<bool> exist(SZ, false);
    auto x = GetX(next);
    auto y = GetY(next);
    auto row = x / 3 * 3;
    auto col = y / 3 * 3;
    for (int i = 0; i < SZ; ++i) {
      if (board[x][i] != ANY) {
        int index = board[x][i] - ONE;
        exist[index] = true;
      }
      if (board[i][y] != ANY) {
        int index = board[i][y] - ONE;
        exist[index] = true;
      }
      auto p = row + i / BLOCK;
      auto q = col + i % BLOCK;
      if (board[p][q] != ANY) {
        int index = board[p][q] - ONE;
        exist[index] = true;
      }
    }
    for (int i = 0; i < SZ; ++i) {
      if (!exist[i]) {
        board[x][y] = static_cast<char>(i + ONE);
        if (Dfs(pBoard, next + 1)) return true;
      }
    }
    board[x][y] = ANY;
    return false;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>>* pBoard) {
    auto& board = *pBoard;
    Dfs(&board, 0);
  }
};

std::vector<std::vector<char>> convert(const std::vector<std::string>& input) {
  std::vector<std::vector<char>> res;
  for (auto&& row : input) {
    std::vector<char> vec;
    for (auto&& c : row) {
      vec.push_back(c);
    }
    res.push_back(vec);
  }
  return res;
}
std::vector<std::string> convert(const std::vector<std::vector<char>>& input) {
  std::vector<std::string> res;
  for (auto&& row : input) {
    std::string str;
    for (auto&& c : row) {
      str += c;
    }
    res.push_back(str);
  }
  return res;
}

TEST(leetcode_37, 1) {
  std::vector<std::string> board = {"53..7....", "6..195...", ".98....6.",
                                    "8...6...3", "4..8.3..1", "7...2...6",
                                    ".6....28.", "...419..5", "....8..79"};
  decltype(board) expect = {"534678912", "672195348", "198342567",
                            "859761423", "426853791", "713924856",
                            "961537284", "287419635", "345286179"};
  auto input = convert(board);
  Solution s;
  s.solveSudoku(&input);
  std::cout << std::endl << input[0][2] << std::endl;
  auto out = convert(input);
  for (int i = 0; i < 9; ++i) {
    // std::cout << out[i] << std::endl;
    EXPECT_EQ(out[i], expect[i]);
  }
}
