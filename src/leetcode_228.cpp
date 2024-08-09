/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/9 09:16
 */
#include <gtest/gtest.h>

class Solution {
    std::string ToString(int start, int end) {
        if (start == end) {
            return std::to_string(start);
        }
        return std::to_string(start) + "->" + std::to_string(end);
    }

public:
    std::vector<std::string> summaryRanges(const std::vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        std::vector<std::string> summary;
        auto sz = nums.size();
        int start = nums[0];
        for (int i = 1; i <= sz; ++i) {
            if (i == sz || nums[i] != nums[i - 1] + 1) {
                summary.push_back(ToString(start, nums[i - 1]));
                if (i < sz) {
                    start = nums[i];
                }
            }
        }
        return summary;
    }
};

TEST(leetcode, 228) {
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    std::vector<std::string> expect = {"0->2", "4->5", "7"};
    auto res = Solution().summaryRanges(nums);
    ASSERT_EQ(res.size(), expect.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i], expect[i]);
    }
}
