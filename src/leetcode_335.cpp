/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-05 21:56
 */

#include <gtest/gtest.h>

class Solution {
  /*               i-2
  case 1 : i-1┌─┐
              └─┼─>i
               i-3

                  i-2
  case 2 : i-1 ┌────┐
               └─══>┘i-3
               i  i-4      (i overlapped i-4)

  case 3 :    i-4
             ┌──┐
             │i<┼─┐
          i-3│ i-5│i-1
             └────┘
              i-2

*/
 public:
  bool isSelfCrossing(const std::vector<int>& x) {
    for (int i = 3; i < x.size(); ++i) {
      if (
          // 与3步前交叉
          x[i] >= x[i - 2] && x[i - 1] <= x[i - 3] ||
          // 与4步前交叉
          i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2] ||
          // 与6步前交叉
          i >= 5 && x[i - 2] >= x[i - 4] && x[i] + x[i - 4] >= x[i - 2] &&
              x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3]) {
        return true;
      }
    }
    return false;
  }
};

TEST(leetcode335, 1) {
  std::vector<int> x = {2, 1, 1, 2};
  ASSERT_EQ(Solution().isSelfCrossing(x), true);
}
