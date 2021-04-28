#include <gtest/gtest.h>

#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    int sz = nums.size();
    for (int i = 0; i < sz - 1; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {-1};
  }
};

TEST(leetcode_1, case1) {
  Solution s;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  auto res = s.twoSum(nums, target);
  EXPECT_EQ(res.size(), 2);
  EXPECT_EQ(res[0], 0);
  EXPECT_EQ(res[1], 1);
}
