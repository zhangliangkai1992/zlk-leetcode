/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/8 08:45
 */

#include <gtest/gtest.h>

class Solution {
public:
    int candy(const std::vector<int> &ratings) {
        std::vector<int> current_candy;
        current_candy.push_back(1);
        // 连续下降的起点
        int last_pos = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                current_candy.push_back(current_candy.back() + 1);
                last_pos = i;
            } else if (ratings[i] == ratings[i - 1]) {
                current_candy.push_back(1);
                last_pos = i;
            } else {
                current_candy.push_back(1);
                int sz = current_candy.size();
                for (int j = sz - 2; j >= last_pos; --j) {
                    if (current_candy[j] < current_candy[j + 1] + 1) {
                        current_candy[j] = current_candy[j + 1] + 1;
                    } else {
                        break;
                    }
                }
            }
            // std::cout << "zlk " << last_pos << std::endl;
        }
        int sum = 0;
        for (auto &&n: current_candy) {
            sum += n;
        }
        return sum;
    }
};

TEST(leetcode, 135) {
    std::vector<int> ratings = {1, 6, 10, 8, 7, 3, 2};
    int sum = 18;
    // {1,2,5,4,3,2,1}
    EXPECT_EQ(Solution().candy(ratings), sum);
}