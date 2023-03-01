/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-02 00:06
 */

#include <include/leetcode_util.h>
#include <stack>

class Solution {
 public:
  std::string simplifyPath(const std::string &s) {
    std::stack<std::string> st;
    std::istringstream iss(s);
    const char kDelim = '/';
    std::string line;
    while (std::getline(iss, line, kDelim)) {
      if (line == "." || line.empty()) {
        continue;
      }
      if (line == "..") {
        if (!st.empty()) {
          st.pop();
        }
        continue;
      }
      st.push(line);
    }
    std::vector<std::string> p;
    while (!st.empty()) {
      p.push_back(st.top());
      st.pop();
    }
    std::string res;
    res += kDelim;
    for (auto it = p.rbegin(); it != p.rend(); ++it) {
      res += *it + kDelim;
    }
    if (res.size() > 1) {
      res.resize(res.size() - 1);
    }
    return res;
  }
};

TEST(leetcode, 71) {
  std::string path = "/home/";
  auto res = Solution().simplifyPath(path);
  decltype(res) expect = "/home";
  ASSERT_EQ(expect, res);
}
