/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-02 23:03
 */
#include <gtest/gtest.h>

class Solution {
 public:
  // 二分查找:n1左边长度l1和n2左边长度l2满足l1+l2==totalLen/2 &&
  // n1[l1-1]<=n2[l2] && n2[l2-1]<=n1[l1]
  double findMedianSortedArrays(const std::vector<int>& n1,
                                const std::vector<int>& n2) {
    auto len1 = n1.size();
    auto len2 = n2.size();
    if (len2 > len1) return findMedianSortedArrays(n2, n1);
    int low = 0;
    int high = len2;
    int len = (len1 + len2 + 1) / 2;
    while (low <= high) {
      int mid = (low + high) / 2;
      auto anotherMid = len - mid;
      if (mid < len2 && n2[mid] < n1[anotherMid - 1]) {
        low = mid + 1;
      } else if (mid > 0 && n2[mid - 1] > n1[anotherMid]) {
        high = mid - 1;
      } else {
        int maxLeft = 0;
        if (mid == 0) {
          maxLeft = n1[anotherMid - 1];
        } else if (anotherMid == 0) {
          maxLeft = n2[mid - 1];
        } else {
          maxLeft = std::max(n1[anotherMid - 1], n2[mid - 1]);
        }
        int minRight = 0;
        if ((len1 + len2) & 1) {
          return maxLeft;
        } else {
          if (mid == len2) {
            minRight = n1[anotherMid];
          } else if (anotherMid == len1) {
            minRight = n2[mid];
          } else {
            minRight = std::min(n1[anotherMid], n2[mid]);
          }
          return (minRight + maxLeft) / 2.0;
        }
      }
    }
    return 0;
  }
};

TEST(leetcode4, 1) {
  std::vector<int> n1 = {1, 3};
  std::vector<int> n2 = {2};
  ASSERT_EQ(Solution().findMedianSortedArrays(n1, n2), 2);
}
TEST(leetcode4, 2) {
  std::vector<int> n1 = {1, 2};
  std::vector<int> n2 = {3, 4};
  ASSERT_EQ(Solution().findMedianSortedArrays(n1, n2), 2.5);
}
