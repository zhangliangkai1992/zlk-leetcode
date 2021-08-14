/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-11 00:08
 */

#include <gtest/gtest.h>

class Solution {
  int cache_[1 << 20] = {0};
  bool dfs(int n, int target, int k) {
    if (cache_[k]) {
      return cache_[k] > 0;
    }
    if (target <= 0) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      // 如果i+1没有人选，且对方不能赢，那么我就能赢
      if (!(k & (1 << i)) && !dfs(n, target - i - 1, k | (1 << i))) {
        cache_[k] = 1;
        return true;
      }
    }
    cache_[k] = -1;
    return false;
  }

 public:
  bool canIWin(int n, int target) {
    int sum = n * (n + 1) / 2;
    if (target < 2) {
      return true;
    } else if (sum < target) {
      return false;
    } else if (sum == target) {
      return n & 1;
    }
    return dfs(n, target, 0);
  }
};

TEST(leetcode464, 1) {
  int n = 10;
  int target = 11;
  bool expect = false;
  ASSERT_EQ(Solution().canIWin(n, target), expect);
}
