/**
 * @Copyright (c) 2022 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2022-11-05 20:29
 */

#include <gtest/gtest.h>

class Skiplist {
  constexpr static int kMaxHeight = 8;
  struct Node {
    int val;
    int height;
    std::vector<Node *> next;
    std::vector<Node *> prev;
  };

  Node *head_;
  size_t sz_;
  int height_;

  static int GetNodeHeight() {
    int h = 1;
    while (h < kMaxHeight && (std::rand() & 1) == 0) ++h;
    return h;
  }
  std::vector<Node *> FindPrev(int target) const {
    auto p = head_;
    int h = height_;
    std::vector<Node *> res(height_, nullptr);
    while (h > 0) {
      if (p->next[h - 1] == head_ ||
          (p->val < target && p->next[h - 1]->val >= target)) {
        res[h - 1] = p;
        --h;
      } else {
        p = p->next[h - 1];
      }
    }
    return res;
  }

  Node *FindNode(int target) const {
    if (sz_ == 0) {
      return head_;
    }
    auto p = head_;
    int h = height_;
    while (h > 0) {
      if (p->next[h - 1] == head_) {
        --h;
        continue;;
      }
      if (p->next[h - 1]->val == target) {
        return p->next[h - 1];
      }
      if (p->next[h - 1]->val > target) {
        --h;
      } else {
        p = p->next[h - 1];
      }
    }
    return head_;
  }

 public:
  ~Skiplist() {
    if (sz_ == 0) {
      delete head_;
      return;
    }
    auto p = head_->next[0];
    while (p != head_) {
      auto q = p->next[0];
      delete p;
      p = q;
    }
    delete head_;
  }

  Skiplist() : sz_(0) {
    head_ = new Node;
    head_->val = 1 << 31;
    head_->height = 0;
    head_->next = std::vector<Node *>(kMaxHeight, head_);
    head_->prev = std::vector<Node *>(kMaxHeight, head_);
    height_ = 0;
  }
  bool search(int target) { return FindNode(target) != head_; }
  void add(int num) {
    ++sz_;
    auto prev = FindPrev(num);
    auto node = new Node;
    node->height = GetNodeHeight();
    node->val = num;
    node->next = std::vector<Node *>(node->height);
    node->prev = std::vector<Node *>(node->height);
    for (int i = 0; i < prev.size() && i < node->height; ++i) {
      node->next[i] = prev[i]->next[i];
      node->prev[i] = prev[i];
      prev[i]->next[i] = node;
      node->next[i]->prev[i] = node;
    }
    for (int i = prev.size(); i < node->height; ++i) {
      head_->next[i] = node;
      node->next[i] = head_;

      head_->prev[i] = node;
      node->prev[i] = head_;
    }
    height_ = std::max(height_, node->height);
  }
  bool erase(int num) {
    auto node = FindNode(num);
    if (node == head_) {
      // not found
      return false;
    }
    --sz_;
    for (int i = 0; i < node->height; ++i) {
      node->next[i]->prev[i] = node->prev[i];
      node->prev[i]->next[i] = node->next[i];
    }
    delete node;
    return true;
  }
};

TEST(leetcode, 1206) {
  Skiplist list;
  list.add(1);
  ASSERT_TRUE(list.search(1));
  list.add(2);
  ASSERT_TRUE(list.search(2));
  list.add(3);
  ASSERT_TRUE(list.search(3));
  ASSERT_FALSE(list.search(0));
  list.add(4);
  ASSERT_TRUE(list.search(4));
  ASSERT_TRUE(list.search(1));
  ASSERT_FALSE(list.erase(0));
}
