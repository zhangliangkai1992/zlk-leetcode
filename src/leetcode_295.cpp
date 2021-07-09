/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-09 22:15
 */
#include <gtest/gtest.h>

#include <queue>

class MedianFinder {
  std::priority_queue<int> small_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> high_;
  bool even_;

 public:
  MedianFinder() : even_(true) {}
  void addNum(int num) {
    if (even_) {
      high_.push(num);
      small_.push(high_.top());
      high_.pop();
    } else {
      small_.push(num);
      high_.push(small_.top());
      small_.pop();
    }
    even_ = !even_;
  }
  double findMedian() {
    if (even_) {
      return (small_.top() + high_.top()) / 2.0;
    }
    return small_.top();
  }
};

TEST(leetcode295, 1) {
  MedianFinder medianFinder;
  medianFinder.addNum(1);
  medianFinder.addNum(2);
  ASSERT_EQ(medianFinder.findMedian(), 1.5);
  medianFinder.addNum(3);
  ASSERT_EQ(medianFinder.findMedian(), 2);
}
