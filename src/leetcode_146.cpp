
/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-05-24 22:17
 */

#include <gtest/gtest.h>

#include <list>
#include <unordered_map>

class LRUCache {
  int cap_;
  std::list<int> keys_;
  typedef std::list<int>::iterator PosType;
  std::unordered_map<int, PosType> keysPos_;
  std::unordered_map<int, int> keyValues_;

 public:
  explicit LRUCache(int capacity) : cap_(capacity) {}

  int get(int key) {
    bool exist = keyValues_.count(key) != 0;
    if (exist) {
      auto value = keyValues_[key];
      keys_.erase(keysPos_[key]);
      keys_.push_front(key);
      keysPos_[key] = keys_.begin();
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    bool exist = keyValues_.count(key) != 0;
    if (exist) {
      keys_.erase(keysPos_[key]);
    }
    keys_.push_front(key);
    keysPos_[key] = keys_.begin();
    keyValues_[key] = value;
    while (keyValues_.size() > cap_) {
      auto evict = keys_.back();
      keys_.pop_back();
      keyValues_.erase(evict);
      keysPos_.erase(evict);
    }
  }
};
TEST(leetcode146, 1) {
  LRUCache cache(2);
  cache.put(1, 2);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 2);
  cache.put(3, 3);
  EXPECT_EQ(cache.get(2), -1);
  cache.put(4, 4);
  EXPECT_EQ(cache.get(1), -1);
  EXPECT_EQ(cache.get(3), 3);
  EXPECT_EQ(cache.get(4), 4);
}
