/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/7 08:40
 */
#include <gtest/gtest.h>
#include <unordered_map>

class RandomizedSet {
public:
    RandomizedSet() : element_pos_(), elements_() {
        auto max_op = 200000;
        elements_.reserve(max_op);
        element_pos_.reserve(max_op);
    }

    bool insert(int val) {
        auto it = element_pos_.find(val);
        if (it != element_pos_.end()) {
            return false;
        }
        element_pos_[val] = elements_.size();
        elements_.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = element_pos_.find(val);
        if (it == element_pos_.end()) {
            return false;
        }
        int pos = it->second;
        elements_[pos] = elements_.back();
        element_pos_[elements_[pos]] = pos;
        elements_.resize(elements_.size() - 1);
        element_pos_.erase(val);
        return true;
    }

    int getRandom() {
        auto random_val = random() % elements_.size();
        return elements_[random_val];
    }

private:
    std::unordered_map<int, int> element_pos_;
    std::vector<int> elements_;
};

TEST(leetcode, 380) {
    RandomizedSet my_set;
    ASSERT_TRUE(my_set.insert(0));
    ASSERT_TRUE(my_set.insert(1));
    ASSERT_TRUE(my_set.remove(0));
    ASSERT_TRUE(my_set.insert(2));
    ASSERT_TRUE(my_set.remove(1));
    ASSERT_EQ(my_set.getRandom(), 2);
}