/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/6 21:56
 */
#include <gtest/gtest.h>

class Solution {
public:
    void merge(std::vector<int> &v1, int m, std::vector<int> &v2, int n) {
        int pos = n + m - 1;
        int v1_pos = m - 1;
        int v2_pos = n - 1;
        while (pos >= 0) {
            if (v1_pos < 0) {
                v1[pos--] = v2[v2_pos--];
            } else if (v2_pos < 0) {
                v1[pos--] = v1[v1_pos--];
            } else if (v1[v1_pos] < v2[v2_pos]) {
                v1[pos--] = v2[v2_pos--];
            } else {
                v1[pos--] = v1[v1_pos--];
            }
        }
    }
};

TEST(leetcode, 88) {
    std::vector<int> v1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> v2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    Solution().merge(v1, m, v2, n);
    std::vector<int> expect = {1, 2, 2, 3, 5, 6};
    for (int i = 0; i < m + n; ++i) {
        EXPECT_EQ(v1[i], expect[i]);
    }
}