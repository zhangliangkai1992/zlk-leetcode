/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-09-01 09:03
 */

#include <gtest/gtest.h>

class Solution {
  void MergeSort(const std::vector<int> &nums, std::vector<int> *pIndexes,
                 size_t low, size_t high, std::vector<int> *pRes) {
    auto sz = high - low;
    if (sz <= 1) {
      return;
    }
    int mid = sz / 2 + low;
    MergeSort(nums, pIndexes, low, mid, pRes);
    MergeSort(nums, pIndexes, mid, high, pRes);
    std::vector<int> tmp;
    tmp.reserve(sz);
    int i1 = low;
    int i2 = mid;
    int halfCount = 0;
    auto &res = *pRes;
    while (i1 < mid || i2 < high) {
      if (i2 == high ||
          (i1 < mid && nums[pIndexes->at(i1)] <= nums[pIndexes->at(i2)])) {
        tmp.push_back(pIndexes->at(i1));
        res[pIndexes->at(i1)] += halfCount;
        ++i1;
      } else {
        tmp.push_back(pIndexes->at(i2));
        ++i2;
        ++halfCount;
      }
    }
    for (auto i = low; i < high; ++i) {
      (*pIndexes)[i] = tmp[i - low];
    }
  }

 public:
  std::vector<int> countSmaller(const std::vector<int> &nums) {
    std::vector<int> indexes;
    size_t sz = nums.size();
    indexes.reserve(sz);
    for (int i = 0; i < sz; ++i) {
      indexes.push_back(i);
    }
    std::vector<int> res(sz, 0);
    MergeSort(nums, &indexes, 0, sz, &res);
    return res;
  }
};

TEST(leetcode, 315) {
  std::vector<int> nums = {5, 2, 6, 1};
  std::vector<int> expect = {2, 1, 1, 0};
  auto res = Solution().countSmaller(nums);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
