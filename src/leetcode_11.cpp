/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-08-07 23:24
 */

#include <include/leetcode_util.h>

class Solution {
 public:
  int maxArea(const std::vector<int> &heights) {
    int sz = heights.size();
    std::vector<int> indexes;
    indexes.push_back(0);
    int res = 0;
    for (int i = 1; i < sz; ++i) {
      auto h = heights[i];
      for (int j = 0; j < indexes.size(); ++j) {
        res =
            std::max(res, (i - indexes[j]) * std::min(h, heights[indexes[j]]));
      }
      if (h > heights[indexes.back()]) {
        indexes.push_back(i);
      }
    }
    return res;
  }
};

TEST(leetcode, 11) {
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int expect = 49;
  ASSERT_EQ(Solution().maxArea(heights), expect);
}
