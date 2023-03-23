/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-23 22:45
 */

#include <include/leetcode_util.h>
#include <map>

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(const std::vector<int> &nums) {
    std::map<int, int> nCount;
    for (auto &&n : nums) {
      ++nCount[n];
    }
    std::vector<std::vector<int>> res = {{}};
    for (auto &&p : nCount) {
      decltype(res) cp;
      cp.swap(res);
      std::vector<int> cur;
      for (int i = 0; i <= p.second; ++i) {
        for (auto &&v : cp) {
          res.emplace_back(v);
          auto &&back = res.back();
          back.insert(back.end(), cur.begin(), cur.end());
        }
        cur.push_back(p.first);
      }
    }
    return res;
  }
};

TEST(leetcode, 90) {
  std::vector<int> nums = {1, 2, 2};
  auto res = Solution().subsetsWithDup(nums);
  decltype(res) expect = {{}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}};
  AssertMatrix(res, expect);
}
