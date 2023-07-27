/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-27 23:14
 */

#include <include/leetcode_util.h>

class Solution {
  bool check(const std::string &s) {
    int low = 0;
    int high = s.size() - 1;
    while (low < high) {
      if (s[low++] != s[high--]) {
        return false;
      }
    }
    return true;
  }

 public:
  std::vector<std::vector<std::string>> partition(const std::string &s) {
    auto sz = s.size();
    if (sz == 0) {
      return {{}};
    }
    if (sz == 1) {
      return {{s}};
    }
    std::vector<std::vector<std::string>> res;
    for (int i = sz - 1; i >= 0; --i) {
      auto sub_str = s.substr(i);
      if (check(sub_str)) {
        auto str_vec = partition(s.substr(0, i));
        for (auto &&vec : str_vec) {
          vec.push_back(s.substr(i));
          res.push_back(vec);
        }
      }
    }
    return res;
  }
};

TEST(leetcode, 131) {
  auto s = "aab";
  auto res = Solution().partition(s);
  decltype(res) expect = {{"a", "a", "b"}, {"aa", "b"}};
  AssertMatrix(res, expect);
}
