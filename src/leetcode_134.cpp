/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/7 09:23
 */
#include <gtest/gtest.h>

class Solution {
public:
    int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) {
        int start = 0;
        int current = 0;
        int gas_cost_diff = 0;
        for (int i = 0; i < gas.size(); ++i) {
            current += gas[i];
            current -= cost[i];
            gas_cost_diff += gas[i] - cost[i];
            if (current < 0) {
                start = i + 1;
                current = 0;
            }
        }
        if (gas_cost_diff < 0) {
            return -1;
        }
        return start;
    }
};

TEST(leetcode, 134) {
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
    int expect = 3;
    ASSERT_EQ(Solution().canCompleteCircuit(gas, cost), expect);
}