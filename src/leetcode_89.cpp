/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-12 09:34
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    if (n == 1) {
      return {0, 1};
    }
    auto res = grayCode(n - 1);
    auto sz = res.size();
    res.reserve(2 * sz);
    for (int i = sz - 1; i >= 0; --i) {
      res.push_back(res[i] | (1 << (n - 1)));
    }
    return res;
  }
};

TEST(leetcode, 89) {
  int n = 2;
  auto res = Solution().grayCode(n);
  decltype(res) expect = {0, 1, 3, 2};
  AssertVector(res, expect);
}
