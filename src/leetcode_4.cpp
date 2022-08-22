/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-02 23:03
 */
#include <gtest/gtest.h>

class Solution {
  using ItType = std::vector<int>::const_iterator;
  int findKth(ItType it1, int len1, ItType it2, int len2, int k) {
    if (len1 > len2) {
      return findKth(it2, len2, it1, len1, k);
    }
    if (len1 == 0) {
      return *(it2 + k - 1);
    }
    if (k == 1) {
      return std::min(*it1, *it2);
    }
    int half = std::min(k / 2, len1);
    int anotherHalf = k - half;
    if (*(it1 + half - 1) < *(it2 + anotherHalf - 1)) {
      return findKth(it1 + half, len1 - half, it2, len2, k - half);
    } else if (*(it1 + half - 1) > *(it2 + anotherHalf - 1)) {
      return findKth(it1, len1, it2 + anotherHalf, len2 - anotherHalf, k - anotherHalf);
    } else {
      return *(it1 + half - 1);
    }
  }
 public:
  double findMedianSortedArrays(const std::vector<int> &n1,
                                const std::vector<int> &n2) {
    int totalLen = n1.size() + n2.size();
    if (totalLen % 2 == 1) {
      return findKth(n1.cbegin(), n1.size(), n2.cbegin(), n2.size(), totalLen / 2 + 1);
    }
    return (findKth(n1.cbegin(), n1.size(), n2.cbegin(), n2.size(), totalLen / 2)
        + findKth(n1.cbegin(), n1.size(), n2.cbegin(), n2.size(), totalLen / 2 + 1)) / 2.0;
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
