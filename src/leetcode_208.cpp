/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-09 22:59
 */
#include <gtest/gtest.h>

class Trie {
  struct Node {
    Node* child[26];
    bool word;
    Node() : word(false) {
      for (auto&& node : child) {
        node = nullptr;
      }
    }
  };
  Node* root_;

 public:
  Trie() { root_ = new Node; }
  void insert(const std::string& str) {
    auto p = root_;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
      int index = str[i] - 'a';
      if (p->child[index] == nullptr) {
        p->child[index] = new Node;
      }
      p->child[index]->word = p->child[index]->word || (i == size - 1);
      p = p->child[index];
    }
  }
  bool search(const std::string& str) {
    auto p = root_;
    for (auto&& c : str) {
      int index = c - 'a';
      if (p->child[index] == nullptr) return false;
      p = p->child[index];
    }
    return p->word;
  }
  bool startsWith(const std::string& str) {
    auto p = root_;
    for (auto&& c : str) {
      int index = c - 'a';
      if (p->child[index] == nullptr) return false;
      p = p->child[index];
    }
    return true;
  }
};

TEST(leetcode208, 1) {
  Trie trie;
  trie.insert("apple");
  ASSERT_EQ(trie.search("apple"), true);
  ASSERT_EQ(trie.search("app"), false);
  ASSERT_EQ(trie.startsWith("app"), true);
  trie.insert("app");
  ASSERT_EQ(trie.search("app"), true);
}
