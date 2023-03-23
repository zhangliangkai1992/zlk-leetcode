/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-23 22:07
 */

#include <include/leetcode_util.h>

class Solution {
  int search(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return -1;
  }

 public:
  std::vector<int> searchRange(const std::vector<int> &nums, int target) {
    auto index = search(nums, target);
    if (index == -1) {
      return {-1, -1};
    }
    int low = index - 1;
    while (low >= 0 && nums[low] == target)
      --low;
    int high = index + 1;
    while (high < nums.size() && nums[high] == target)
      ++high;
    return {low + 1, high - 1};
  }
};

TEST(leetcode, 34) {
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 6;
  auto res = Solution().searchRange(nums, target);
  decltype(res) expect = {-1, -1};
  AssertVector(expect, res);
}
