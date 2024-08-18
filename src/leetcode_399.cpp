/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/17 21:21
 */
#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<double>
    calcEquation(const std::vector<std::vector<std::string>> &equations, std::vector<double> &values,
                 std::vector<std::vector<std::string>> &queries) {
        auto sz = equations.size();
        std::unordered_map<std::string, std::shared_ptr<std::unordered_map<std::string, double>>> str_value;
        for (int i = 0; i < sz; ++i) {
            auto it0 = str_value.find(equations[i][0]);
            auto it1 = str_value.find(equations[i][1]);
            if (it0 == str_value.end() && it1 == str_value.end()) {
                std::shared_ptr<std::unordered_map<std::string, double>> str_to_double(
                        new std::unordered_map<std::string, double>);
                (*str_to_double)[equations[i][0]] = values[i];
                (*str_to_double)[equations[i][1]] = 1;
                str_value[equations[i][0]] = str_to_double;
                str_value[equations[i][1]] = str_to_double;
            } else if (it0 == str_value.end() && it1 != str_value.end()) {
                auto str_to_double = it1->second;
                (*str_to_double)[equations[i][0]] = (*str_to_double)[equations[i][1]] * values[i];
                str_value[equations[i][0]] = str_to_double;
            } else if (it0 != str_value.end() && it1 == str_value.end()) {
                auto str_to_double = it0->second;
                (*str_to_double)[equations[i][1]] = (*str_to_double)[equations[i][0]] / values[i];
                str_value[equations[i][1]] = str_to_double;
            } else {
                auto str_to_double0 = it0->second;
                auto str_to_double1 = it1->second;
                (*str_to_double0)[equations[i][1]] = (*str_to_double0)[equations[i][0]] / values[i];
                str_value[equations[i][1]] = str_to_double0;
                double rate = (*str_to_double0)[equations[i][0]] / ((*str_to_double1)[equations[i][1]] * values[i]);
                for (auto &&item: *str_to_double1) {
                    if (str_to_double0->find(item.first) != str_to_double0->end()) {
                        continue;
                    }
                    (*str_to_double0)[item.first] = item.second * rate;
                    str_value[item.first] = str_to_double0;
                }
            }
        }
        std::vector<double> res;
        for (auto &&query: queries) {
            std::unordered_set<std::string> current_set;
            auto it0 = str_value.find(query[0]);
            auto it1 = str_value.find(query[1]);
            if (it0 == str_value.end() || it1 == str_value.end() || it0->second != it1->second) {
                res.push_back(-1);
                continue;
            }
            auto str_to_double = it0->second;
            res.push_back((*str_to_double)[query[0]] / (*str_to_double)[query[1]]);
        }
        return res;
    }
};

TEST(leetcode, 399) {
    std::vector<std::vector<std::string>> equations = {{"a", "b"},
                                                       {"e", "f"},
                                                       {"b", "e"}};
    std::vector<double> values = {3.4, 1.4, 2.3};
    decltype(equations) queries = {{"a", "f"}};
    auto res = Solution().calcEquation(equations, values, queries);
    decltype(res) expect = {10.948};
    ASSERT_EQ(expect.size(), res.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i], expect[i]);
    }
}