/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-19 23:22
 */

#include <include/leetcode_util.h>

class Solution {
  std::unordered_map<int, int> cache_;

 public:
  int numTrees(int n) {
    if (cache_.find(n) != cache_.end()) {
      return cache_[n];
    }
    if (n == 0 || n == 1) {
      cache_[n] = 1;
      return cache_[n];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res += numTrees(i - 1) * numTrees(n - i);
    }
    cache_[n] = res;
    return cache_[n];
  }
};

TEST(leetcode, 96) {
  int n = 3;
  int expect = 5;
  ASSERT_EQ(Solution().numTrees(n), expect);
}

