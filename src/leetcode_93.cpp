/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-28 18:47
 */

#include <gtest/gtest.h>

class Solution {
  void dfs(const std::string &s, int count, std::vector<std::string> *pRes,
           std::string *pCurrent) {
    if (count >= 4) {
      if (s.empty()) {
        pRes->push_back(pCurrent->substr(0, pCurrent->size() - 1));
      }
      return;
    }
    if (s.empty()) {
      return;
    }
    auto &&current = *pCurrent;
    // 1位
    current += s.substr(0, 1) + ".";
    dfs(s.substr(1), count + 1, pRes, &current);
    current.pop_back();
    while (!current.empty() && current.back() != '.') current.pop_back();
    auto sz = s.size();
    if (s[0] == '0' || sz < 2) {
      return;
    }

    // 2位
    current += s.substr(0, 2) + ".";
    dfs(s.substr(2), count + 1, pRes, &current);
    current.pop_back();
    while (!current.empty() && current.back() != '.') current.pop_back();

    // 3位
    if (sz < 3 || std::stoi(s.substr(0, 3)) > 255) {
      return;
    }
    current += s.substr(0, 3) + ".";
    dfs(s.substr(3), count + 1, pRes, &current);
    current.pop_back();
    while (!current.empty() && current.back() != '.') current.pop_back();
  }

 public:
  std::vector<std::string> restoreIpAddresses(const std::string &s) {
    auto sz = s.size();
    if (sz < 4 || sz > 12) return {};
    std::vector<std::string> res;
    std::string current;
    dfs(s, 0, &res, &current);
    return res;
  }
};

TEST(leetcode93, 1) {
  auto s = "25525511135";
  auto res = Solution().restoreIpAddresses(s);
  decltype(res) expect = {"255.255.11.135", "255.255.111.35"};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
