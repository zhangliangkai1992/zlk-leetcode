/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-08 20:42
 */

#include <gtest/gtest.h>

#include <unordered_set>

class Solution {
 public:
  bool canCross(const std::vector<int>& stones) {
    std::unordered_map<int, std::unordered_set<int>> prevK;
    for (auto&& pos : stones) {
      prevK[pos] = std::unordered_set<int>();
    }
    prevK[0] = {0};
    decltype(prevK) cur = prevK;
    while (!cur.empty()) {
      decltype(cur) next;
      for (auto&& p : cur) {
        auto pos = p.first;
        for (auto&& k : p.second) {
          for (int j = -1; j < 2; ++j) {
            if (k + j <= 0) continue;
            auto nextPos = pos + k + j;
            if (prevK.count(nextPos) && !prevK[nextPos].count(k + j)) {
              if (nextPos == stones.back()) return true;
              next[nextPos].insert(k + j);
              prevK[nextPos].insert(k + j);
            }
          }
        }
      }
      cur = next;
    }
    return false;
  }
};

TEST(leetcode403, 1) {
  std::vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  ASSERT_EQ(Solution().canCross(stones), true);
}
