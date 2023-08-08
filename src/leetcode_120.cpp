/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-08-08 23:00
 */

#include <include/leetcode_util.h>

class Solution {
public:
  int minimumTotal(const std::vector<std::vector<int>> &triangle) {
    auto last = triangle[0];
    const int kMax = 10000000;
    int res = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
      res = kMax;
      decltype(last) next;
      auto sz = triangle[i].size();
      for (int j = 0; j < sz; ++j) {
        if (j == 0) {
          next.push_back(triangle[i][j] + last[j]);
        } else if (j == sz - 1) {
          next.push_back(triangle[i][j] + last[j - 1]);
        } else {
          next.push_back(triangle[i][j] + std::min(last[j], last[j - 1]));
        }
        res = std::min(res, next.back());
      }
      last = next;
    }
    return res;
  }
};

TEST(leetcode, 120) {
  std::vector<std::vector<int>> triangle = {
      {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int expect = 11;
  ASSERT_EQ(expect, Solution().minimumTotal(triangle));
}