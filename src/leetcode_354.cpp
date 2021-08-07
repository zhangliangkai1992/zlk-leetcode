/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-05 23:18
 */

#include <gtest/gtest.h>
class Solution {
 public:
  int maxEnvelopes(const std::vector<std::vector<int>>& envelopes) {
    auto cmp = [](const std::vector<int>& v1, const std::vector<int>& v2) {
      // 宽度升序，高度降序
      if (v1[0] == v2[0]) return v1[1] > v2[1];
      return v1[0] < v2[0];
    };
    auto sortedVec = envelopes;
    std::sort(sortedVec.begin(), sortedVec.end(), cmp);
    // 求最长升序高度
    std::vector<int> hight;
    for (auto&& v : sortedVec) {
      auto h = v[1];
      if (hight.empty() || h > hight.back()) {
        hight.push_back(h);
      } else {
        for (int i = hight.size() - 1; i >= 0; --i) {
          if (i == 0 || hight[i - 1] < h) {
            hight[i] = std::min(hight[i], h);
            break;
          }
        }
      }
    }
    return hight.size();
  }
};

TEST(leetcode354, 1) {
  std::vector<std::vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  int expect = 3;
  ASSERT_EQ(Solution().maxEnvelopes(envelopes), expect);
}

TEST(leetcode354, 2) {
  std::vector<std::vector<int>> envelopes = {
      {1, 2}, {3, 4}, {3, 5}, {4, 5}, {5, 5}, {5, 6}, {6, 7}, {7, 8}, {2, 3}};
  int expect = 7;
  ASSERT_EQ(Solution().maxEnvelopes(envelopes), expect);
}
