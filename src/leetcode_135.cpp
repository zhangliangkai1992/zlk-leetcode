/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-15 00:34
 */
#include <include/leetcode_util.h>

class Solution {
 public:
  int candy(const std::vector<int> &ratings) {
    auto sz = ratings.size();
    std::vector<int> res(sz, 1);
    int count = 1;
    for (int i = 1; i < sz; ++i) {
      if (ratings[i - 1] < ratings[i]) {
        res[i] = std::max(++count, res[i]);
      } else {
        count = 1;
      }
    }
    for (int i = sz - 2; i >= 0; --i) {
      if (ratings[i + 1] < ratings[i]) {
        res[i] = std::max(++count, res[i]);
      } else {
        count = 1;
      }
    }
    int sum = 0;
    for (auto &&n : res) {
      sum += n;
    }
    return sum;
  }
};

TEST(leetcode, 135) {
  std::vector<int> ratings = {1, 2, 2};
  auto res = Solution().candy(ratings);
  ASSERT_EQ(res, 4);
}
