/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-03 21:53
 */

#include <gtest/gtest.h>

class Solution {
  void dfs(const std::string& s, const std::vector<std::string>& wordDict,
           std::string* current, std::vector<std::string>* res) {
    if (s.empty()) {
      // 去除最后一个空格
      res->push_back(current->substr(0, current->size() - 1));
      return;
    }
    for (auto&& word : wordDict) {
      auto sz = word.size();
      if (sz <= s.size() && s.substr(0, sz) == word) {
        (*current) += word;
        current->push_back(' ');
        dfs(s.substr(sz), wordDict, current, res);
        current->pop_back();
        while (!current->empty() && current->back() != ' ') {
          current->pop_back();
        }
      }
    }
  }

 public:
  std::vector<std::string> wordBreak(const std::string& s,
                                     const std::vector<std::string>& wordDict) {
    std::vector<std::string> res;
    std::string current;
    dfs(s, wordDict, &current, &res);
    return res;
  }
};

TEST(leetcode140, 1) {
  std::string s = "catsanddog";
  std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  decltype(wordDict) expect = {"cat sand dog", "cats and dog"};
  auto res = Solution().wordBreak(s, wordDict);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
