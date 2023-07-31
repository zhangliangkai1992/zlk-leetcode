/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-31 21:48
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int maxProfit(const std::vector<int> &prices) {
    int res = 0;
    int min_prices = ~(1 << 31);
    for (auto &&n : prices) {
      min_prices = std::min(min_prices, n);
      res = std::max(res, n - min_prices);
    }
    return res;
  }
};

TEST(leetcode, 121) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  int expect = 5;
  ASSERT_EQ(expect, Solution().maxProfit(prices));
}
