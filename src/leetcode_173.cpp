/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/9/7 10:55
 */

#include <gtest/gtest.h>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(v), left(l), right(r) {}
};

class BSTIterator {
public:
    explicit BSTIterator(TreeNode *root) {
        auto p = root;
        while (p) {
            st_.push(p);
            p = p->left;
        }
    }

    int next() {
        auto p = st_.top();
        st_.pop();
        int value = p->val;
        p = p->right;
        while (p) {
            st_.push(p);
            p = p->left;
        }
        return value;
    }

    bool hasNext() {
        return !st_.empty();
    }

private:
    std::stack<TreeNode *> st_;
};

TEST(leetcode, 173) {

}