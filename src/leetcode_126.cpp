/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-04-24 01:16
 */

#include <include/leetcode_util.h>

#include <queue>

class Solution {
  bool checkWord(const std::string &s1, const std::string &s2) {
    if (s1.size() != s2.size()) {
      return false;
    }
    int diff = 0;
    for (size_t i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i] && ++diff > 1) {
        return false;
      }
    }
    return diff == 1;
  }

  // 找到以first为开头，每个元素的上一个元素有哪些
  auto getParent(const std::vector<std::set<int>> &nextMap, int first) const {
    std::queue<int> que;
    que.push(first);
    std::vector<int> distance(nextMap.size(), 1000);
    distance[first] = 0;
    std::vector<std::vector<int>> parent(nextMap.size());
    parent[first].push_back(-1);
    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      for (auto &&next : nextMap[front]) {
        if (distance[next] > distance[front] + 1) {
          distance[next] = distance[front] + 1;
          que.push(next);
          parent[next].clear();
          parent[next].push_back(front);
        } else if (distance[next] == distance[front] + 1) {
          parent[next].push_back(front);
        }
      }
    }
    return parent;
  }
  void dfs(const std::vector<std::vector<int>> &parent, int current,
           std::vector<int> *path, std::vector<std::vector<int>> *allPath) {
    if (current == -1) {
      allPath->push_back(*path);
      return;
    }
    for (auto &&p : parent[current]) {
      path->push_back(p);
      dfs(parent, p, path, allPath);
      path->pop_back();
    }
  }

 public:
  std::vector<std::vector<std::string>> findLadders(
      const std::string &beginWord, const std::string &endWord,
      const std::vector<std::string> &wordList) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < wordList.size(); ++i) {
      if (wordList[i] == beginWord) {
        first = i;
      }
      if (wordList[i] == endWord) {
        last = i;
      }
    }
    if (last == -1) {
      return {};
    }
    auto wordVec = wordList;
    if (first == -1) {
      wordVec.push_back(beginWord);
      first = wordVec.size() - 1;
    }
    auto sz = wordVec.size();
    std::vector<std::set<int>> nextMap(sz);
    for (size_t i = 0; i < sz - 1; ++i) {
      for (size_t j = i + 1; j < sz; ++j) {
        if (checkWord(wordVec[i], wordVec[j])) {
          nextMap[i].insert(j);
          nextMap[j].insert(i);
        }
      }
    }
    auto parent = getParent(nextMap, first);
    std::vector<std::vector<int>> allPath;
    std::vector<int> path;
    dfs(parent, last, &path, &allPath);
    std::vector<std::vector<std::string>> res;
    for (auto &&p : allPath) {
      res.emplace_back();
      res.back().push_back(endWord);
      auto cp = p;
      cp.pop_back();
      for (auto &&n : cp) {
        res.back().push_back(wordVec[n]);
      }
      std::reverse(res.back().begin(), res.back().end());
    }
    return res;
  }
};

TEST(leetcode, 126) {
  std::vector<std::string> wordList = {"hot", "dot", "dog",
                                       "lot", "log", "cog"};
  auto start = "hit";
  auto end = "cog";
  auto res = Solution().findLadders(start, end, wordList);
  decltype(res) expect = {{"hit", "hot", "dot", "dog", "cog"},
                          {"hit", "hot", "lot", "log", "cog"}};
  AssertMatrix(res, expect);
}
