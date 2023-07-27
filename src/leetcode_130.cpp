/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-23 21:56
 */

#include <include/leetcode_util.h>

#include <queue>

class Solution {
 public:
  void solve(std::vector<std::vector<char>> *p_board) {
    auto &&board = *p_board;
    using Pos = std::pair<int, int>;
    int m = board.size();
    int n = board[0].size();
    std::set<Pos> visited;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X') {
          continue;
        }
        Pos pos = {i, j};
        if (visited.find(pos) != visited.end()) {
          continue;
        }
        bool modify = true;
        std::queue<Pos> que;
        que.push(pos);
        decltype(visited) current;
        current.insert(pos);
        while (!que.empty()) {
          auto front = que.front();
          que.pop();
          std::vector<Pos> kNextDir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
          for (auto &&dir : kNextDir) {
            Pos next = {front.first + dir.first, front.second + dir.second};
            if (next.first < 0 || next.first >= m || next.second < 0 ||
                next.second >= n) {
              modify = false;
            } else if (board[next.first][next.second] != 'X' &&
                       current.find(next) == current.end()) {
              current.insert(next);
              que.push(next);
            }
          }
        }
        if (modify) {
          for (auto &&p : current) {
            board[p.first][p.second] = 'X';
          }
        }
        visited.insert(current.begin(), current.end());
      }
    }
  }
};

TEST(leetcode_130, 1) {
  std::vector<std::vector<char>> board = {
      {'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'},
  };
  decltype(board) expect = {
      {'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'},
  };
  Solution().solve(&board);
  AssertMatrix(expect, board);
}
