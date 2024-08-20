/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/19 23:58
 */

#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
    int gcd(int a, int b) {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

public:
    int maxPoints(const std::vector<std::vector<int>> &points) {
        auto sz = points.size();
        std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, std::unordered_set<int>>>> lines;
        int res = 1;
        for (int i = 0; i < sz - 1; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                /**
                 * line form a * x + b * y = k
                 * p1[0] * a + p1[1] * b = k;
                 * p2[0] * a + p2[1] * b = k;
                 * (p1[0] - p2[0]) * a + (p1[1] - p2[1]) * b = 0
                 */
                int a = points[j][1] - points[i][1];
                int b = points[i][0] - points[j][0];
                if (a < 0) {
                    a = -a;
                    b = -b;
                }
                if (a == 0) {
                    b = 1;
                } else if (b == 0) {
                    a = 1;
                } else {
                    int g = gcd(a, std::abs(b));
                    a = a / g;
                    b = b / g;
                }
                int k = a * points[i][0] + b * points[i][1];
                lines[a][b][k].insert(i);
                lines[a][b][k].insert(j);
                res = std::max(res, static_cast<int>(lines[a][b][k].size()));
            }
        }
        return res;
    }
};

TEST(leetcode, 149) {
    std::vector<std::vector<int>> points = {
            {9,  -25},
            {-4, 1},
            {-1, 5},
            {-7, 7}
    };
    int expect = 3;
    ASSERT_EQ(Solution().maxPoints(points), expect);
}