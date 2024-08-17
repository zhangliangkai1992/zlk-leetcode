/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/17 20:02
 */

#include <gtest/gtest.h>

class Solution {
public:
    std::vector<std::vector<int>>
    insert(const std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
        std::vector<std::vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        if (newInterval[1] < intervals[0][0]) {
            res.push_back(newInterval);
            for (auto &&v: intervals) {
                res.push_back(v);
            }
            return res;
        }
        int current_index = 0;
        auto sz = intervals.size();
        while (current_index < sz && intervals[current_index][1] < newInterval[0]) {
            res.push_back(intervals[current_index++]);
        }
        if (current_index == sz) {
            res.push_back(newInterval);
            return res;
        }
        int start = std::min(intervals[current_index][0], newInterval[0]);
        int end = newInterval[1];
        while (current_index < sz &&
               !(intervals[current_index][1] < newInterval[0] || intervals[current_index][0] > newInterval[1])) {
            end = std::max(newInterval[1], intervals[current_index++][1]);
        }
        res.push_back({start, end});
        while (current_index < sz) {
            res.push_back(intervals[current_index++]);
        }
        return res;
    }
};

TEST(leetcode, 57) {
    std::vector<std::vector<int>> intervals = {
            {3,  5},
            {12, 15}};
    std::vector<int> newInterval = {6, 6};
    decltype(intervals) expect = {{3,  5},
                                  {6,  6},
                                  {12, 15}};
    auto res = Solution().insert(intervals, newInterval);
    ASSERT_EQ(res.size(), expect.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i].size(), 2);
        ASSERT_EQ(res[i][0], expect[i][0]);
        ASSERT_EQ(res[i][1], expect[i][1]);
    }
}
