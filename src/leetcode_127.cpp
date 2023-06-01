/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-04-24 00:33
 */

#include <include/leetcode_util.h>

#include <queue>

class Solution {
  bool check(const std::string &s1, const std::string &s2) {
    if (s1.size() != s2.size()) {
      return false;
    }
    int diff = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        ++diff;
      }
      if (diff > 1) {
        return false;
      }
    }
    return diff == 1;
  }

 public:
  int ladderLength(const std::string &beginWord, const std::string &endWord,
                   const std::vector<std::string> &wordList) {
    std::set<std::string> sets;
    for (auto &&s : wordList) {
      sets.insert(s);
    }
    sets.insert(beginWord);
    std::vector<std::string> allWord;
    for (auto &&s : sets) {
      allWord.push_back(s);
    }
    auto sz = allWord.size();
    std::vector<std::vector<int>> next(sz);
    int startIndex = -1;
    int endIndex = -1;
    for (int i = 0; i < sz; ++i) {
      if (beginWord == allWord[i]) {
        startIndex = i;
      }
      if (endWord == allWord[i]) {
        endIndex = i;
      }
      for (int j = i + 1; j < sz; ++j) {
        if (check(allWord[i], allWord[j])) {
          next[i].push_back(j);
          next[j].push_back(i);
        }
      }
    }
    if (endIndex == -1) {
      return 0;
    }
    std::vector<bool> hasAccessed(sz, false);
    std::queue<int> que;
    que.push(startIndex);
    hasAccessed[startIndex] = true;
    int count = 1;
    while (!que.empty()) {
      auto queLen = que.size();
      for (int i = 0; i < queLen; ++i) {
        auto front = que.front();
        for (auto &n : next[front]) {
          if (n == endIndex) {
            return count + 1;
          }
          if (!hasAccessed[n]) {
            hasAccessed[n] = true;
            que.push(n);
          }
        }
        que.pop();
      }
      ++count;
    }
    return 0;
  }
};

TEST(leetcode, 127) {
  std::vector<std::string> wordList = {"hot", "dot", "dog",
                                       "lot", "log", "cog"};
  auto start = "hit";
  auto end = "cog";
  auto res = Solution().ladderLength(start, end, wordList);
  ASSERT_EQ(res, 5);
}
