/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-27 23:34
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int minJumps(const std::vector<int> &arr) {
    // BFS
    auto sz = arr.size();
    std::vector<int> res(sz, -1);
    std::unordered_map<int, std::vector<int>> valueIndex;
    for (int i = 0; i < sz; ++i) {
      valueIndex[arr[i]].push_back(i);
    }
    std::vector<int> curIndex = {0};
    res[0] = 0;
    int steps = 0;
    while (!curIndex.empty()) {
      ++steps;
      decltype(curIndex) nextIndex;
      nextIndex.reserve(sz);
      for (auto &&i : curIndex) {
        if (i + 1 < sz && -1 == res[i + 1]) {
          nextIndex.push_back(i + 1);
          res[i + 1] = steps;
        }
        if (i - 1 >= 0 && -1 == res[i - 1]) {
          nextIndex.push_back(i - 1);
          res[i - 1] = steps;
        }
        auto &&indexVec = valueIndex[arr[i]];
        for (auto &&j : indexVec) {
          if (-1 == res[j]) {
            nextIndex.push_back(j);
            res[j] = steps;
          }
        }
        // 访问过的索引必须清空，不然下次还会进行循环
        indexVec.clear();
      }
      curIndex = nextIndex;
    }
    return res.back();
  }
};

TEST(leetcode1345, 1) {
  std::vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  int expect = 3;
  ASSERT_EQ(Solution().minJumps(arr), expect);
}
