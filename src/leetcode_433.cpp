/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/19 22:02
 */
#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>

class Solution {
    bool diff_string(const std::string &s1, const std::string &s2) {
        auto sz = s1.size();
        if (s2.size() != sz) {
            return false;
        }
        int diff_count = 0;
        for (int i = 0; i < sz; ++i) {
            if (s1[i] != s2[i] && ++diff_count > 1) {
                return false;
            }
        }
        return diff_count == 1;
    }

public:
    int minMutation(const std::string &startGene, const std::string &endGene, const std::vector<std::string> &bank) {
        if (bank.empty()) {
            return -1;
        }
        bool contain_end = false;
        for (auto &&s: bank) {
            if (endGene == s) {
                contain_end = true;
            }
        }
        if (!contain_end) {
            return -1;
        }
        auto cp_bank = bank;
        cp_bank.push_back(startGene);
        auto sz = cp_bank.size();
        std::unordered_map<std::string, std::unordered_set<std::string>> diff_str;
        for (int i = 0; i < sz - 1; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (diff_string(cp_bank[i], cp_bank[j])) {
                    diff_str[cp_bank[i]].insert(cp_bank[j]);
                    diff_str[cp_bank[j]].insert(cp_bank[i]);
                }
            }
        }
        std::unordered_set<std::string> current_set;
        current_set.insert(startGene);
        auto all_set = current_set;
        int count = 0;
        while (!current_set.empty()) {
            ++count;
            decltype(current_set) next_set;
            for (auto &&item: current_set) {
                auto it = diff_str.find(item);
                if (it == diff_str.end()) {
                    continue;
                }
                for (auto &&next: it->second) {
                    if (next == endGene) {
                        return count;
                    }
                    auto all_it = all_set.find(next);
                    if (all_it != all_set.end()) {
                        continue;
                    }
                    all_set.insert(next);
                    next_set.insert(next);
                }
            }
            current_set.swap(next_set);
        }
        return -1;
    }
};

TEST(leetcode, 433) {
    std::string start = "AAAAAAAA";
    std::string end = "CCCCCCCC";
    std::vector<std::string> bank = {"AAAAAAAA", "AAAAAAAC", "AAAAAACC", "AAAAACCC", "AAAACCCC", "AACACCCC", "ACCACCCC",
                                     "ACCCCCCC", "CCCCCCCA"};
    int expect = -1;
    ASSERT_EQ(expect, Solution().minMutation(start, end, bank));
}
