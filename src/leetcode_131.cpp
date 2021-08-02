/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-02 21:43
 */

#include <gtest/gtest.h>

class Solution {
  void dfs(const std::string &s, std::vector<std::string> *current,
           std::vector<std::vector<std::string>> *res) {
    if (s.empty()) {
      res->push_back(*current);
      return;
    }
    auto sz = s.size();
    for (int i = 1; i <= sz; ++i) {
      auto str = s.substr(0, i);
      auto rev = str;
      std::reverse(rev.begin(), rev.end());
      if (str != rev) {
        continue;
      }
      current->push_back(str);
      dfs(s.substr(i, sz - i), current, res);
      current->pop_back();
    }
  }

 public:
  std::vector<std::vector<std::string>> partition(const std::string &s) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> current;
    dfs(s, &current, &res);
    return res;
  }
};

TEST(leetcode131, 1) {
  std::string s = "aab";
  auto res = Solution().partition(s);
  decltype(res) expect = {{"a", "a", "b"}, {"aa", "b"}};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
