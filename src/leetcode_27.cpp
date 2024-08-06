/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/6 22:27
 */
#include <gtest/gtest.h>

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int count = 0;
        for (auto &&n: nums) {
            if (n == val) {
                ++count;
            }
        }
        auto sz = nums.size();
        int left = 0;
        int right = sz - 1;
        while (left < right) {
            while (left < right && nums[left] != val) {
                ++left;
            }
            while (left < right && nums[right] == val) {
                --right;
            }
            if (left < right) {
                nums[left] = nums[right];
                nums[right] = val;
                ++left;
                --right;
            }
        }
        return nums.size() - count;
    }
};

TEST(leetcode, 27) {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    std::vector<int> expect = {2, 2};
    EXPECT_EQ(expect.size(), Solution().removeElement(nums, val));
    for (int i = 0; i < expect.size(); ++i) {
        EXPECT_EQ(expect[i], nums[i]);
    }
}