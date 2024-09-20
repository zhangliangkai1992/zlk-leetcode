/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/9/13 00:33
 */

#include <gtest/gtest.h>

class Solution {
    int sum_;
    int n_;
    std::vector<std::string> board_;

    bool Check(int row, int col) {
        for (int i = 0; i < n_; ++i) {
            if (i != row && board_[i][col] == board_[row][col]) {
                return false;
            }
            auto j = i;
            if (j != col && board_[row][j] == board_[row][col]) {
                return false;
            }
            j = row + col - i;
            if (j >= 0 && j < n_ && i != row && board_[i][j] == board_[row][col]) {
                return false;
            }
            j = col - row + i;
            if (j >= 0 && j < n_ && i != row && board_[i][j] == board_[row][col]) {
                return false;
            }
        }
        return true;
    }

    void Dfs(int row) {
        if (row == n_) {
            ++sum_;
            return;
        }
        for (int j = 0; j < n_; ++j) {
            board_[row][j] = '1';
            if (Check(row, j)) {
                Dfs(row + 1);
            }
            board_[row][j] = '0';
        }
    }

public:
    int totalNQueens(int n) {
        sum_ = 0;
        board_.reserve(n);
        n_ = n;
        for (int i = 0; i < n; ++i) {
            board_.emplace_back(n, '0');
        }
        Dfs(0);
        return sum_;
    }
};

TEST(leetcode, 52) {
    int n = 4;
    int res = Solution().totalNQueens(n);
    int expect = 2;
    ASSERT_EQ(expect, res);
}