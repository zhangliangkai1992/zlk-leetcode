/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-07-29 17:30
 */

#include <include/leetcode_util.h>

class Solution {
  std::vector<std::string> dfs(const std::string &s, int part) {
    if (part == 0) {
      if (s.empty()) {
        return {{""}};
      } else {
        return {};
      }
    }
    std::vector<std::string> res;
    if (s.empty()) {
      return {};
    }
    if (s[0] == '0') {
      auto ret = dfs(s.substr(1), part - 1);
      for (auto &&part_str : ret) {
        res.push_back(std::string("0.") + part_str);
      }
      return res;
    }
    const int kMinLen = 1;
    const int kMaxLen = 3;
    const int kMaxValue = 255;
    for (int len = kMinLen; len <= kMaxLen && len <= s.size(); ++len) {
      auto value = std::stoi(s.substr(0, len));
      if (value > kMaxValue) {
        continue;
      }
      auto ret = dfs(s.substr(len), part - 1);
      for (auto &&part_str : ret) {
        auto str = std::to_string(value);
        str += "." + part_str;
        res.push_back(str);
      }
    }
    return res;
  }

 public:
  std::vector<std::string> restoreIpAddresses(const std::string &s) {
    for (auto &&c : s) {
      if (c >= '0' && c <= '9') {
      } else {
        return {};
      }
    }
    auto res = dfs(s, 4);
    for (auto &&str : res) {
      str.resize(str.size() - 1);
    }
    return res;
  }
};

TEST(leetcode, 93) {
  auto s = "101023";
  auto res = Solution().restoreIpAddresses(s);
  decltype(res) expect = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3",
                          "101.0.2.3"};
  AssertVector(res, expect);
}
