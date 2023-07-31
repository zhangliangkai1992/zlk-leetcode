/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-31 21:56
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int maxProfit(const std::vector<int> &prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int diff = prices[i] - prices[i - 1];
      if (diff > 0) {
        res += diff;
      }
    }
    return res;
  }
};

TEST(leetcode, 122) {
  const std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  int expect = 7;
  ASSERT_EQ(expect, Solution().maxProfit(prices));
}
