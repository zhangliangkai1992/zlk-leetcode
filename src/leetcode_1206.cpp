
/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-06-02 21:35
 */
#include <gtest/gtest.h>

#include <algorithm>
#include <random>

class Skiplist {
  constexpr static int MAX_HEIGHT = 12;

 private:
  struct Node {
    int num;
    int height;
    std::vector<Node*> next;
    std::vector<Node*> prev;
  };
  Node* header_;
  int node_sz_;

  int GetRandomHeight() const {
    int height = 1;
    while (height < MAX_HEIGHT && std::rand() & 1) ++height;
    // std::cout << height << std::endl;
    return height;
  }

  // 获取所有每层之前单节点
  std::vector<Node*> GetPrevNode(int height, int num) {
    auto p = header_;
    std::vector<Node*> prev;
    for (int i = height - 1; i >= 0; --i) {
      auto q = p;
      while (q->next[i] != header_ && num > q->next[i]->num) q = q->next[i];
      prev.push_back(q);
      p = q;
    }
    std::reverse(prev.begin(), prev.end());
    return prev;
  }

  Node* find_node(int target) {
    auto p = header_;
    auto index = header_->height - 1;
    while (index >= 0) {
      if (p->next[index] == header_ || p->next[index]->num > target) {
        --index;
        continue;
      }
      if (p->next[index]->num == target) {
        return p->next[index];
      }
      p = p->next[index];
    }
    return header_;
  }

 public:
  Skiplist() {
    header_ = new Node;
    header_->height = 1;
    header_->next = std::vector<Node*>(MAX_HEIGHT, header_);
    header_->prev = std::vector<Node*>(MAX_HEIGHT, header_);
    node_sz_ = 0;
    std::srand(time(nullptr));
  }
  bool search(int target) { return find_node(target) != header_; }

  void add(int num) {
    int height = GetRandomHeight();
    auto prev = GetPrevNode(height, num);
    auto node = new Node;
    node->height = height;
    node->num = num;
    node->next = std::vector<Node*>(height, nullptr);
    node->prev = std::vector<Node*>(height, nullptr);
    for (int i = 0; i < height; ++i) {
      node->next[i] = prev[i]->next[i];
      prev[i]->next[i]->prev[i] = node;
      prev[i]->next[i] = node;
      node->prev[i] = prev[i];
    }
    ++node_sz_;
    header_->height = std::max(height, header_->height);
  }

  bool erase(int num) {
    auto node = find_node(num);
    if (node == header_) return false;
    for (int i = 0; i < node->height; ++i) {
      node->prev[i]->next[i] = node->next[i];
      node->next[i]->prev[i] = node->prev[i];
    }
    delete node;
    --node_sz_;
    return true;
  }
  ~Skiplist() {
    auto p = header_->next[0];
    while (p->next[0] != header_) {
      auto q = p->next[0];
      delete p;
      p = q;
    }
    delete header_;
  }
};
TEST(leetcode_1206, 1) {
  Skiplist l;
  l.add(3);
  l.add(8);
  l.add(5);
  EXPECT_EQ(l.search(3), true);
  EXPECT_EQ(l.search(5), true);
  EXPECT_EQ(l.search(8), true);
  EXPECT_EQ(l.search(1), false);
  l.erase(5);
  EXPECT_EQ(l.search(5), false);
}
