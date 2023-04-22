/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-04-22 23:55
 */

#include <include/leetcode_util.h>

class Solution {
  void dfs(std::vector<std::vector<int>> *res, std::vector<int> *path,
           int start, int end, int k) {
    if (path->size() == k) {
      res->push_back(*path);
      return;
    }
    for (int i = start; i <= end; ++i) {
      path->push_back(i);
      dfs(res, path, i + 1, end, k);
      path->pop_back();
    }
  }

 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    dfs(&res, &path, 1, n, k);
    return res;
  }
};
TEST(leetcode, 77) {
  int n = 4;
  int k = 2;
  auto res = Solution().combine(n, k);
  decltype(res) expect = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  AssertMatrix(res, expect);
}
