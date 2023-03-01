/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-01 23:55
 */

#include <include/leetcode_util.h>

class Solution {
  inline std::string convert(const std::string &s) {
    auto copy = s;
    std::sort(copy.begin(), copy.end());
    return copy;
  }

 public:
  std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> res;
    std::map<std::string, std::vector<std::string>> keyStr;
    for (auto &&s : strs) {
      keyStr[convert(s)].push_back(s);
    }
    for (auto &&p : keyStr) {
      res.push_back(p.second);
    }
    return res;
  }
};

TEST(leetcode, 49) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = Solution().groupAnagrams(strs);
  decltype(res) expect = {{"bat"}, {"eat", "tea", "ate"}, {"tan", "nat"}};
  AssertMatrix(res, expect);
}
