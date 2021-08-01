/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-17 23:20
 */

#include <gtest/gtest.h>

class Solution {
 public:
  int characterReplacement(const std::string& s, int k) {
    auto sz = s.size();
    int count[26] = {0};
    // 滑动窗口[left,right)
    int left = 0;
    int maxLen = 0;
    int maxCount = 0;
    for (int right = 0; right < sz; ++right) {
      maxCount = std::max(maxCount, ++count[s[right] - 'A']);
      while (right - left + 1 - maxCount > k) {
        count[s[left++] - 'A']--;
      }
      maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

TEST(leetcode424, 1) {
  ASSERT_EQ(Solution().characterReplacement("AABB", 2), 4);
}
