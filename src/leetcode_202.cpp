/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/9 09:02
 */

#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }
        std::unordered_set<int> nums;
        int current = n;
        while (nums.find(current) == nums.end()) {
            // std::cout << "zlk " << current << std::endl;
            nums.insert(current);
            int sum = 0;
            while (current) {
                auto remain = current % 10;
                sum += remain * remain;
                current /= 10;
            }
            if (sum == 1) {
                return true;
            }
            current = sum;
        }
        return false;
    }
};

TEST(leetcode, 202) {
    // EXPECT_FALSE(Solution().isHappy(2));
    EXPECT_TRUE(Solution().isHappy(19));
}