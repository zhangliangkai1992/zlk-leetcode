/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-13 20:37
 */
#include <gtest/gtest.h>

class Solution {
  std::vector<int> dir_x = {0, 1, 0, -1};
  std::vector<int> dir_y = {1, 0, -1, 0};
  bool search(const std::vector<std::vector<char>>& board, int i, int j,
              std::vector<std::vector<bool>>* access, const std::string& word,
              int index) {
    if (index == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() ||
        (*access)[i][j] || board[i][j] != word[index]) {
      return false;
    }

    // search in 4 direction
    (*access)[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      if (search(board, i + dir_x[k], j + dir_y[k], access, word, index + 1)) {
        return true;
      }
    }
    (*access)[i][j] = false;
    return false;
  }

 public:
  bool exist(const std::vector<std::vector<char>>& board,
             const std::string& word) {
    if (word.empty()) return true;
    if (board.empty()) return false;
    std::vector<std::vector<bool>> access(
        board.size(), std::vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (search(board, i, j, &access, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
TEST(leetcode_79, 1) {
  Solution s;
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string word = "ABCCED";
  EXPECT_EQ(s.exist(board, word), true);
  word = "SEE";
  EXPECT_EQ(s.exist(board, word), true);
  word = "ABCB";
  EXPECT_EQ(s.exist(board, word), false);
}
