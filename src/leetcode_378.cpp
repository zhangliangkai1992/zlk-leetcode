/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-09-30 09:24
 */

#include <gtest/gtest.h>
#include <queue>

class Solution {
  using Matrix = std::vector<std::vector<int>>;

 public:
  int kthSmallest(const Matrix &matrix, int k) {
    using Item = std::tuple<int, int, int>;
    using Container = std::vector<Item>;
    auto cmp = [](const Item &i1, const Item &i2) {
      return std::get<2>(i1) > std::get<2>(i2);
    };
    std::priority_queue<Item, Container, decltype(cmp)> que(cmp);

    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
      que.push(std::make_tuple(0, i, matrix[0][i]));
    }
    for (int i = 0; i < k - 1; ++i) {
      auto &&t = que.top();
      int row = std::get<0>(t);
      int col = std::get<1>(t);
      que.pop();
      ++row;
      if (row < n) {
        que.push(std::make_tuple(row, col, matrix[row][col]));
      }
    }
    return std::get<2>(que.top());
  }
};

TEST(leetcode, 378) {
  using Matrix = std::vector<std::vector<int>>;
  Matrix matrix = {
      {1, 5, 9}, {10, 11, 13}, {12, 13, 15}
  };

  int k = 8;
  ASSERT_EQ(Solution().kthSmallest(matrix, k), 13);
}
