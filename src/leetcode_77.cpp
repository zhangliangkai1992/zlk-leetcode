/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/15 21:41
 */
#include <gtest/gtest.h>

class Solution {
    void dfs(std::vector<std::vector<int>> *res, std::vector<int> *path, int n, int k) {
        if (path->size() == k) {
            res->push_back(*path);
            return;
        }
        int back = path->back();
        for (int i = back + 1; i <= n; ++i) {
            path->push_back(i);
            dfs(res, path, n, k);
            path->pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        path.reserve(k);
        for (int i = 1; i + k - 1 <= n; ++i) {
            path.push_back(i);
            dfs(&res, &path, n, k);
            path.pop_back();
        }
        return res;
    }
};

TEST(leetcode, 77) {
    int n = 4;
    int k = 2;
    auto res = Solution().combine(n, k);
    decltype(res) expect = {{1, 2},
                            {1, 3},
                            {1, 4},
                            {2, 3},
                            {2, 4},
                            {3, 4}};
    ASSERT_EQ(res.size(), expect.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i].size(), k);
        ASSERT_EQ(expect[i].size(), k);
        for (int j = 0; j < k; ++j) {
            ASSERT_EQ(res[i][j], expect[i][j]);
        }
    }
}
