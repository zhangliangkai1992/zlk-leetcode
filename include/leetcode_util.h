/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-05 10:30
 */

#ifndef INCLUDE_LEETCODE_UTIL_H_
#define INCLUDE_LEETCODE_UTIL_H_
#include <gtest/gtest.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>

void AssertVector(const std::vector<int> &n1, const std::vector<int> &n2) {
  ASSERT_EQ(n1.size(), n2.size());
  for (int i = 0; i < n1.size(); ++i) {
    ASSERT_EQ(n1[i], n2[i]);
  }
}

void AssertMatrix(const std::vector<std::vector<int>> &m1,
                  const std::vector<std::vector<int>> &m2) {
  ASSERT_EQ(m1.size(), m2.size());
  for (int i = 0; i < m1.size(); ++i) {
    AssertVector(m1[i], m2[i]);
  }
}

void AssertSubVectorEqual(const std::vector<int> &v1, int sz,
                          const std::vector<int> &v2) {
  ASSERT_LE(sz, v2.size());
  for (int i = 0; i < sz; ++i) {
    ASSERT_EQ(v1[i], v2[i]);
  }
}

#endif  // INCLUDE_LEETCODE_UTIL_H_
