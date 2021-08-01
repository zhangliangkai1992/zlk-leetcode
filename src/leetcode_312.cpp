/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-01 21:47
 */

#include <gtest/gtest.h>

// hard
class Solution {
  std::unordered_map<int, std::unordered_map<int, int>> coins;
  // 最后剩余[low,high]可以获取的最多硬币数
  int calcCoins(const std::vector<int>& nums, int low, int high) {
    if (low + 1 == high) return 0;
    if (coins[low][high] != 0) {
      return coins[low][high];
    }
    int res = 0;
    for (int i = low + 1; i < high; ++i) {
      res =
          std::max(res, nums[low] * nums[high] * nums[i] +
                            calcCoins(nums, low, i) + calcCoins(nums, i, high));
    }
    coins[low][high] = res;
    return res;
  }

 public:
  int maxCoins(const std::vector<int>& nums) {
    int sz = nums.size();
    // 左右添加1
    auto other = nums;
    other.insert(other.begin(), 1);
    other.push_back(1);
    // 带记忆的递归，自顶向下
    // return calcCoins(other, 0, sz + 1);

    // 按照递归的顺序计算，自底向上
    // 加上左右的两个1的长度
    sz += 2;
    std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));
    for (int len = 2; len < sz; ++len) {
      for (int low = 0; low < sz - len; ++low) {
        int high = low + len;
        auto mul = other[low] * other[high];
        for (int i = low + 1; i < high; ++i) {
          dp[low][high] = std::max(dp[low][high],
                                   other[i] * mul + dp[low][i] + dp[i][high]);
        }
      }
    }
    return dp[0][sz - 1];
  }
};

TEST(leetcode312, 1) {
  std::vector<int> nums = {3, 1, 5, 8};
  int expect = 167;
  ASSERT_EQ(Solution().maxCoins(nums), expect);
}

TEST(leetcode312, 2) {
  std::vector<int> nums(500, 100);
  int expect = 498010100;
  ASSERT_EQ(Solution().maxCoins(nums), expect);
}
