/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-05 10:30
 */

#ifndef INCLUDE_LEETCODE_UTIL_H_
#define INCLUDE_LEETCODE_UTIL_H_
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

void AssertVector(const std::vector<int> &n1, const std::vector<int> &n2) {
  ASSERT_EQ(n1.size(), n2.size());
  for (int i = 0; i < n1.size(); ++i) {
    ASSERT_EQ(n1[i], n2[i]);
  }
}

#endif  // INCLUDE_LEETCODE_UTIL_H_
