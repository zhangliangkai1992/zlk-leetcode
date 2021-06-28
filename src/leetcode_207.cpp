/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-28 23:28
 */
#include <gtest/gtest.h>

#include <unordered_set>

class Solution {
 public:
  // 拓扑排序
  bool canFinish(int numCourses,
                 const std::vector<std::vector<int>>& prerequisites) {
    typedef std::unordered_set<int> SetType;
    std::vector<SetType> deps(numCourses);
    for (auto&& v : prerequisites) {
      deps[v[0]].insert(v[1]);
    }
    auto contains = [](const SetType& s1, const SetType& s2) {
      for (auto&& n : s2) {
        if (s1.find(n) == s1.end()) return false;
      }
      return true;
    };
    SetType cur;
    std::vector<bool> hasStudy(numCourses, false);
    int course = 0;
    while (course < numCourses) {
      int nextCourse = -1;
      for (int i = 0; i < numCourses; ++i) {
        if (!hasStudy[i] && contains(cur, deps[i])) {
          nextCourse = i;
          hasStudy[i] = true;
          cur.insert(i);
          break;
        }
      }
      if (nextCourse == -1) return false;
      ++course;
    }
    return true;
  }
};

TEST(leetcode_207, 1) {
  int numCourses = 2;
  std::vector<std::vector<int>> prerequisites{{1, 0}};

  EXPECT_EQ(Solution().canFinish(numCourses, prerequisites), true);
}
