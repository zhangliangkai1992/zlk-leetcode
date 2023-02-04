/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-04 21:20
 */

#include <gtest/gtest.h>

class Solution {
  int findTopK(const std::vector<int> &nums1, int low1, int high1,
               const std::vector<int> &nums2, int low2, int high2, int k) {
    if (high1 - low1 > high2 - low2) {
      return findTopK(nums2, low2, high2, nums1, low1, high1, k);
    }
    if (low1 >= high1) {
      return nums2[low2 + k - 1];
    }
    if (k == 1) {
      return std::min(nums1[low1], nums2[low2]);
    }
    int len1 = std::min(k / 2, high1 - low1);
    int len2 = k - len1;
    if (nums1[low1 + len1 - 1] < nums2[low2 + len2 - 1]) {
      return findTopK(nums1, low1 + len1, high1, nums2, low2, high2, k - len1);
    } else if (nums1[low1 + len1 - 1] > nums2[low2 + len2 - 1]) {
      return findTopK(nums1, low1, high1, nums2, low2 + len2, high2, k - len2);
    }
    return nums1[low1 + len1 - 1];
  }

public:
  double findMedianSortedArrays(const std::vector<int> &nums1,
                                const std::vector<int> &nums2) {
    auto sz1 = nums1.size();
    auto sz2 = nums2.size();
    auto totalSz = sz1 + sz2;
    double res = findTopK(nums1, 0, sz1, nums2, 0, sz2, totalSz / 2 + 1);
    if ((totalSz & 1) == 0) {
      res += findTopK(nums1, 0, sz1, nums2, 0, sz2, totalSz / 2);
      res /= 2;
    }
    return res;
  }
};

TEST(leetcode, 4) {
  std::vector<int> nums1 = {1};
  std::vector<int> nums2 = {2, 3, 4};
  double expect = 2.5;
  ASSERT_EQ(Solution().findMedianSortedArrays(nums1, nums2), expect);
}
