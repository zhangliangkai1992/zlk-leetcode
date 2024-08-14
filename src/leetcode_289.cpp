/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/14 09:02
 */
#include <gtest/gtest.h>

class Solution {
    int CheckLive(const std::vector<std::vector<int>> &board, int row, int col) {
        int live_count = 0;
        for (int i = -1; i < 2; ++i) {
            if (row + i < 0 || row + i >= board.size()) {
                continue;
            }
            for (int j = -1; j < 2; ++j) {
                if (col + j < 0 || col + j >= board[row + i].size()) {
                    continue;
                }
                live_count += board[row + i][col + j];
            }
        }
        live_count -= board[row][col];
        if (board[row][col]) {
            return live_count == 2 || live_count == 3;
        }
        return live_count == 3;
    }

public:
    void gameOfLife(std::vector<std::vector<int>> &board) {
        auto cp_board = board;
        for (int i = 0; i < cp_board.size(); ++i) {
            for (int j = 0; j < cp_board[i].size(); ++j) {
                board[i][j] = CheckLive(cp_board, i, j);
            }
        }
    }
};

TEST(leetcode, 289) {
    std::vector<std::vector<int>> board = {{0, 1, 0},
                                           {0, 0, 1},
                                           {1, 1, 1}};
    decltype(board) expect = {{0, 0, 0},
                              {1, 0, 1},
                              {0, 1, 1}};
    Solution().gameOfLife(board);
    ASSERT_EQ(board.size(), expect.size());
    for (int i = 0; i < board.size(); ++i) {
        ASSERT_EQ(board[i].size(), expect.size());
        for (int j = 0; j < board[i].size(); ++j) {
            ASSERT_EQ(board[i][j], expect[i][j]);
        }
    }
}
