/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-11 17:35
 */
#include <gtest/gtest.h>

class Solution {
 public:
  int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
    auto n = static_cast<int>(dungeon.size());
    auto m = static_cast<int>(dungeon[0].size());
    const int MAX = ~(1 << 31);
    std::vector<std::vector<int>> hp(n + 1, std::vector<int>(m + 1, MAX));
    hp[n][m - 1] = 1;
    hp[n - 1][m] = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        hp[i][j] = std::min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
        if (hp[i][j] < 1) hp[i][j] = 1;
      }
    }
    return hp[0][0];
  }
};

TEST(leetcode174, 1) {
  std::vector<std::vector<int>> dungeon = {
      {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  ASSERT_EQ(Solution().calculateMinimumHP(dungeon), 7);
}
