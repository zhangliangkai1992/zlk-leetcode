/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/26 21:32
 */

#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *BuildNode(const std::vector<int> &nums) {
    std::shared_ptr<ListNode> pivot(new ListNode);
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        auto node = new ListNode(*it, pivot->next);
        pivot->next = node;
    }
    return pivot->next;
}

std::vector<int> PrintNode(ListNode *head) {
    auto p = head;
    std::vector<int> vec;
    while (p) {
        vec.push_back(p->val);
        p = p->next;
    }
    return vec;
}

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        std::shared_ptr<ListNode> pivot(new ListNode(0, head));
        auto p = pivot.get();
        while (p->next) {
            std::vector<ListNode *> nodes;
            auto q = p;
            for (int i = 0; i < k; ++i) {
                if (q->next == nullptr) {
                    return pivot->next;
                }
                nodes.push_back(q->next);
                q = q->next;
            }
            auto last = nodes.back()->next;
            for (int i = k - 1; i > 0; --i) {
                nodes[i]->next = nodes[i - 1];
            }
            nodes[0]->next = last;
            p->next = q;
            p = nodes[0];
        }
        return pivot->next;

    }
};

TEST(leetcode, 25) {
    std::vector<int> nums = {1, 2};
    auto node = BuildNode(nums);
    auto vec = PrintNode(node);
    EXPECT_EQ(vec.size(), nums.size());
    for (int i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], nums[i]);
    }
    int k = 2;
    auto res = Solution().reverseKGroup(node, k);
    auto res_vec = PrintNode(res);
    decltype(res_vec) expect_vec = {2, 1};
    for (int i = 0; i < expect_vec.size(); ++i) {
        EXPECT_EQ(expect_vec[i], res_vec[i]);
    }
}