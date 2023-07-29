/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 20:27
 */

#include <include/leetcode_util.h>

class Solution {
  std::vector<std::string> res_;
  std::string path_;
  void dfs(int left, int right, int n) {
    if (path_.size() == 2 * n) {
      res_.push_back(path_);
      return;
    }
    if (left < n) {
      path_.push_back('(');
      dfs(left + 1, right, n);
      path_.pop_back();
    }
    if (right < left) {
      path_.push_back(')');
      dfs(left, right + 1, n);
      path_.pop_back();
    }
  }

 public:
  std::vector<std::string> generateParenthesis(int n) {
    path_.reserve(2 * n);
    dfs(0, 0, n);
    return res_;
  }
};

TEST(leetcode, 22) {
  int n = 3;
  auto res = Solution().generateParenthesis(n);
  decltype(res) expect = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  AssertVector(res, expect);
}
