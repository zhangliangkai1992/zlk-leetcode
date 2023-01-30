//
// Created by zlk on 11/13/22.
//

#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>> &prerequistites) {
        std::vector<std::unordered_set<int>> deps(numCourses);
        std::vector<int> res;
        for (auto &&vec: prerequistites) {
            deps[vec[0]].insert(vec[1]);
        }
        std::vector<bool> used(numCourses, false);
        while (res.size() < numCourses) {
            bool found = false;
            int cur = 0;
            for (int i = 0; i < numCourses; ++i) {
                if (used[i]) {
                    continue;
                }
                if (deps[i].empty()) {
                    res.push_back(i);
                    used[i] = true;
                    found = true;
                    cur = i;
                    break;
                }
            }
            if (!found) {
                return {};
            }
            for (int i = 0; i < numCourses; ++i) {
                if (used[i]) {
                    continue;
                }
                deps[i].erase(cur);
            }
        }
        return res;

    }
};

TEST(leetcode, 210) {
    std::vector<std::vector<int>> prerequistites = {{1, 0},
                                                    {2, 0},
                                                    {3, 1},
                                                    {3, 2}};
    int numCourses = 4;
    auto res = Solution().findOrder(numCourses, prerequistites);
    ASSERT_EQ(res.size(), numCourses);
}
