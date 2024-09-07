/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/26 23:19
 */

#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val = 0, ListNode *next = nullptr) : val(val), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return head;
        }
        std::shared_ptr<ListNode> less(new ListNode);
        auto last_less = less.get();
        std::shared_ptr<ListNode> equal(new ListNode);
        auto last_equal = equal.get();
        std::shared_ptr<ListNode> greater(new ListNode);
        auto last_greater = greater.get();
        auto p = head;
        while (p) {
            auto q = p->next;
            if (p->val < x) {
                last_less->next = p;
                last_less = p;
                p->next = nullptr;
            } else if (p->val == x) {
                last_equal->next = p;
                last_equal = p;
                p->next = nullptr;
            } else {
                last_greater->next = p;
                last_greater = p;
                p->next = nullptr;
            }
            p = q;
        }
        if (greater->next) {
            last_equal->next = greater->next;
            if (equal->next == nullptr) {
                equal->next = greater->next;
            }
        }
        if (equal->next) {
            last_less->next = equal->next;
            if (less->next) {
                less->next = equal->next;
            }
        }
        return less->next;
    }
};

TEST(leetcode, 86) {

}