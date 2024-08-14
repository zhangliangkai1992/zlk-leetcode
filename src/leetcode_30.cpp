/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/13 21:18
 */

#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findSubstring(const std::string &s, const std::vector<std::string> &words) {
        std::vector<int> sub_index;
        std::map<int, std::string> pos_str;
        std::unordered_map<std::string, int> word_count;
        for (auto &&word: words) {
            ++word_count[word];
        }
        int word_len = 0;
        for (auto it = word_count.begin(); it != word_count.end(); ++it) {
            auto word = it->first;
            auto pos = s.find(word, 0);
            while (pos != std::string::npos) {
                pos_str[pos] = word;
                pos = s.find(word, pos + 1);
            }
            word_len = word.size();
        }
        for (auto it = pos_str.begin(); it != pos_str.end(); ++it) {
            if (it->first + word_len * words.size() > s.size()) {
                break;
            }
            auto cp_count = word_count;
            bool is_concatenated_str = true;
            for (int i = 0; i < words.size(); ++i) {
                auto word = s.substr(it->first + i * word_len, word_len);
                if (--cp_count[word] < 0) {
                    is_concatenated_str = false;
                    break;
                }
            }
            if (is_concatenated_str) {
                sub_index.push_back(it->first);
            }
        }
        return sub_index;
    }
};

TEST(leetcode, 30) {
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words = {"word", "good", "best", "good"};
    std::vector<int> expect = {8};
    auto res = Solution().findSubstring(s, words);
    ASSERT_EQ(res.size(), expect.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i], expect[i]);
    }
}