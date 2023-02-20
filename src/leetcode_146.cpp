/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-02-21 00:33
 */

#include <include/leetcode_util.h>

#include <list>

class LRUCache {
  int cap_;
  mutable std::list<int> key_order_;
  std::unordered_map<int, int> kv_;
  mutable std::unordered_map<int, decltype(key_order_.begin())> key_pos_;

 public:
  explicit LRUCache(int capacity) : cap_(capacity) {}
  int get(int key) const {
    auto it = key_pos_.find(key);
    if (it == key_pos_.end()) {
      return -1;
    }
    key_order_.erase(it->second);
    key_order_.push_front(key);
    key_pos_[key] = key_order_.begin();
    auto key_it = kv_.find(key);
    return key_it->second;
  }
  void put(int key, int value) {
    auto it = key_pos_.find(key);
    if (it != key_pos_.end()) {
      key_order_.erase(it->second);
    } else if (kv_.size() >= cap_) {
      auto back = key_order_.back();
      key_order_.pop_back();
      key_pos_.erase(back);
      kv_.erase(back);
    }
    kv_[key] = value;
    key_order_.push_front(key);
    key_pos_[key] = key_order_.begin();
  }
};

TEST(leetcode, 146) {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  auto r1 = cache.get(1);
  ASSERT_EQ(r1, 1);
  cache.put(3, 3);
  auto r2 = cache.get(2);
  ASSERT_EQ(r2, -1);
  cache.put(4, 4);
  auto r3 = cache.get(1);
  ASSERT_EQ(r3, -1);
  auto r4 = cache.get(3);
  ASSERT_EQ(r4, 3);
  auto r5 = cache.get(4);
  ASSERT_EQ(r5, 4);
}
