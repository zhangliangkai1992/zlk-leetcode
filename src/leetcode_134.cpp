/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-13 09:22
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int canCompleteCircuit(const std::vector<int> &gas,
                         const std::vector<int> &cost) {
    int sum = gas[0] - cost[0];
    int current = gas[0];
    auto sz = gas.size();
    int res = 0;
    for (int i = 1; i < sz; ++i) {
      sum += gas[i] - cost[i];
      current -= cost[i];
      if (current < 0) {
        current = 0;
        res = i;
      }
      current += gas[i];
    }
    return sum < 0 ? -1 : res + 1;
  }
};

TEST(leetcode, 134) {
  std::vector<int> gas = {5, 8, 2, 8};
  std::vector<int> cost = {6, 5, 6, 6};
  ASSERT_EQ(Solution().canCompleteCircuit(gas, cost), 4);
}
