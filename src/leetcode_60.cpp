/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-10 22:29
 */

#include <include/leetcode_util.h>

class Solution {
  std::vector<int64_t> factorial_;
  std::vector<int> used;
  int findKthSmall(int kth) const {
    for (int i = 0; i < used.size(); ++i) {
      if (!used[i]) {
        if (kth-- == 0) {
          return i;
        }
      }
    }
    return 0;
  }
  std::string selfPermutation(int k) {
    std::string res;
    if (k == 0) {
      for (int i = 0; i < used.size(); ++i) {
        if (!used[i]) {
          res.push_back('1' + i);
        }
      }
      return res;
    }
    int kth = k / factorial_.back();
    auto index = findKthSmall(kth);
    used[index] = true;
    res.push_back('1' + index);
    int nextK = k % factorial_.back();
    factorial_.pop_back();
    res += selfPermutation(nextK);
    return res;
  }

 public:
  std::string getPermutation(int n, int k) {
    factorial_.push_back(1);
    for (int i = 2; i < n; ++i) {
      factorial_.push_back(factorial_.back() * i);
    }
    used = std::vector<int>(n, 0);
    return selfPermutation(k - 1);
  }
};

TEST(leetcode, 60) {
  int n = 4;
  int k = 9;
  auto res = Solution().getPermutation(n, k);
  decltype(res) expect = "2314";
  ASSERT_EQ(res, expect);
}
