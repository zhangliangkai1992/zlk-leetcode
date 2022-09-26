/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-08-26 09:34
 */

#include <gtest/gtest.h>
#include <algorithm>

class Solution {
  int MergeSort(std::vector<int64_t> *pSums,
                int left,
                int right,
                int low,
                int high) {
    int len = right - left;
    if (len <= 1) {
      return 0;
    }
    int mid = left + len / 2;
    int count = MergeSort(pSums, left, mid, low, high)
        + MergeSort(pSums, mid, right, low, high);

    int m = mid;
    int n = mid;
    for (int i = left; i < mid; ++i) {
      while (m < right && pSums->at(m) - pSums->at(i) < low)++m;
      while (n < right && pSums->at(n) - pSums->at(i) <= high)++n;
      count += n - m;
    }
    // 归并排序
    int i1 = left;
    int i2 = mid;
    std::vector<int64_t> tmpIndex;
    tmpIndex.reserve(len);
    while (i1 < mid || i2 < right) {
      if (i2 == right || (i1 < mid && pSums->at(i1) <= pSums->at(i2))) {
        tmpIndex.push_back(pSums->at(i1));
        ++i1;
      } else {
        tmpIndex.push_back(pSums->at(i2));
        ++i2;
      }
    }
    for (int i = left; i < right; ++i) {
      (*pSums)[i] = tmpIndex[i - left];
    }
    return count;
  }

 public:
  int countRangeSum(const std::vector<int> &nums, int low, int high) {
    std::vector<int64_t> sums = {0L};
    for (auto &&n : nums) {
      sums.push_back(sums.back() + n);
    }
    return MergeSort(&sums, 0, sums.size(), low, high);
  }
};
TEST(leetcode, 327) {
  std::vector<int> nums = {2147483647, -2147483648, -1, 0};
  int low = -1;
  int high = 0;
  ASSERT_EQ(Solution().countRangeSum(nums, low, high), 4);
}
