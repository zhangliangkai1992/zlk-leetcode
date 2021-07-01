/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-01 23:01
 */
#include <gtest/gtest.h>

class Solution {
  // 左括号 >= 右括号
  void dfs(const int n, char* buf, int left, int total,
           std::vector<std::string>* res) {
    if (total == 2 * n) {
      res->push_back(buf);
      return;
    }
    if (left < n) {
      buf[total] = '(';
      dfs(n, buf, left + 1, total + 1, res);
      buf[total] = 0;
    }
    if (total - left < left) {
      buf[total] = ')';
      dfs(n, buf, left, total + 1, res);
      buf[total] = 0;
    }
  }

 public:
  std::vector<std::string> generateParenthesis(int n) {
    char* buf = new char[2 * n + 1];
    memset(buf, 0, 2 * n + 1);
    std::vector<std::string> res;
    dfs(n, buf, 0, 0, &res);
    delete[] buf;
    return res;
  }
};

TEST(leetcode22, 1) {
  int n = 3;
  std::vector<std::string> expect = {"((()))", "(()())", "(())()", "()(())",
                                     "()()()"};
  auto res = Solution().generateParenthesis(n);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
