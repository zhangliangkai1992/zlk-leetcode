/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/20 21:09
 */

#include <gtest/gtest.h>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(const std::vector<int> &n1, const std::vector<int> &n2, int k) {
        auto sz1 = n1.size();
        auto sz2 = n2.size();
        long long low = n1[0] + n2[0];
        long long high = n1[sz1 - 1] + n2[sz2 - 1];
        while (low < high) {
            auto mid = (high + low) >> 1;
            long long count = 0;
            for (int i = 0, j = sz2 - 1; i < sz1; ++i) {
                while (j >= 0 && n1[i] + n2[j] > mid) {
                    --j;
                }
                count += j + 1;
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < sz1; ++i) {
            for (int j = 0; j < sz2 && n1[i] + n2[j] < low; ++j) {
                res.push_back({n1[i], n2[j]});
            }
        }
        std::unordered_map<int, int> counts;
        for (auto &&v: n2) {
            ++counts[v];
        }
        for (int i = 0; i < sz1; ++i) {
            auto count = counts[low - n1[i]];
            while (count > 0 && res.size() < k) {
                res.push_back({n1[i], static_cast<int>(low - n1[i])});
                --count;
            }
        }
        return res;
    }
};


TEST(leetcode, 373) {
    std::vector<int> n1 = {1, 7, 11};
    std::vector<int> n2 = {2, 4, 6};
    int k = 3;
    std::vector<std::vector<int>> expect = {{1, 2},
                                            {1, 4},
                                            {1, 6}};
    auto res = Solution().kSmallestPairs(n1, n2, k);
    ASSERT_EQ(res.size(), k);
    for (int i = 0; i < k; ++i) {
        ASSERT_EQ(res[i][0], expect[i][0]);
        ASSERT_EQ(res[i][1], expect[i][1]);
    }
}