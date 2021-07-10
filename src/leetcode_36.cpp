/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-10 12:56
 */
#include <gtest/gtest.h>

#include <unordered_set>

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    const int SZ = 9;
    const char ANY = '.';
    std::string row = "row";
    std::string col = "col";
    std::string block = "block";
    std::unordered_set<std::string> all;
    for (int i = 0; i < SZ; ++i) {
      for (int j = 0; j < SZ; ++j) {
        if (board[i][j] == ANY) continue;
        std::ostringstream rowOss;
        rowOss << i << row << board[i][j];
        if (all.find(rowOss.str()) != all.end()) {
          return false;
        }
        all.insert(rowOss.str());
        std::ostringstream colOss;
        colOss << j << col << board[i][j];
        if (all.find(colOss.str()) != all.end()) {
          return false;
        }
        all.insert(colOss.str());
        int blockIndex = i / 3 * 3 + j / 3;
        std::ostringstream blockOss;
        blockOss << blockIndex << block << board[i][j];
        if (all.find(blockOss.str()) != all.end()) {
          return false;
        }
        all.insert(blockOss.str());
      }
    }
    return true;
  }
};

std::vector<std::vector<char>> convert(const std::vector<std::string>& strs) {
  std::vector<std::vector<char>> res;
  for (auto&& str : strs) {
    std::vector<char> chs;
    for (auto&& ch : str) {
      chs.push_back(ch);
    }
    res.push_back(chs);
  }
  return res;
}
TEST(leetcode36, 1) {
  std::vector<std::string> input = {"53..7....", "6..195...", ".98....6.",
                                    "8...6...3", "4..8.3..1", "7...2...6",
                                    ".6....28.", "...419..5", "....8..79"};
  auto board = convert(input);
  ASSERT_EQ(Solution().isValidSudoku(board), true);
}
