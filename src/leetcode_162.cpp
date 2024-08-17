/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/17 19:13
 */
#include <gtest/gtest.h>


class Solution {
public:
    int findPeakElement(const std::vector<int> &nums) {
        auto sz = nums.size();
        if (sz == 1) {
            return 0;
        }
        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                if (nums[0] > nums[1]) {
                    return 0;
                }
            } else if (i == sz - 1) {
                if (nums[i] > nums[i - 1]) {
                    return i;
                }
            } else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};

TEST(leetcode, 162) {
    std::vector<int> nums = {1, 2, 3, 1};
    auto res = Solution().findPeakElement(nums);
    int expect = 2;
    ASSERT_EQ(expect, res);
}
