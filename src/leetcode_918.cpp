/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/15 22:05
 */

#include <gtest/gtest.h>

class Solution {
public:
    int maxSubarraySumCircular(const std::vector<int> &nums) {
        auto sz = nums.size();
        int max_sum = 0;
        int current_sum = 0;
        int max_num = 1 << 31;
        for (decltype(sz) i = 0; i < sz; ++i) {
            current_sum += nums[i];
            if (current_sum < 0) {
                current_sum = 0;
            } else {
                max_sum = std::max(max_sum, current_sum);
            }
            max_num = std::max(max_num, nums[i]);
        }
        if (max_num < 0) {
            return max_num;
        }
        current_sum = 0;
        std::vector<int> max_till_sum(sz);
        for (decltype(sz) i = 0; i < sz; ++i) {
            current_sum += nums[i];
            max_till_sum[i] = std::max(i > 0 ? max_till_sum[i - 1] : nums[i], current_sum);
        }
        current_sum = 0;
        for (decltype(sz) i = sz - 1; i >= 1; --i) {
            current_sum += nums[i];
            max_sum = std::max(max_sum, max_till_sum[i - 1] + current_sum);
        }
        return max_sum;
    }
};

TEST(leetcode, 918) {
    std::vector<int> nums = {5, -3, 5};
    int expect = 10;
    ASSERT_EQ(Solution().maxSubarraySumCircular(nums), expect);
}