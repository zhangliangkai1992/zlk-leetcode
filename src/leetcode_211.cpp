/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/9 09:45
 */
#include <gtest/gtest.h>

#include <memory>

class WordDictionary {
public:
    WordDictionary() {
        root_ = std::make_shared<Node>('a');
    }

    void addWord(const std::string &s) {
        auto p = root_;
        for (auto &&c: s) {
            auto child_index = c - 'a';
            if (p->children_node[child_index] == nullptr) {
                p->children_node[child_index] = std::make_shared<Node>(c);
            }
            p = p->children_node[child_index];
        }
        p->leaf = true;
    }

    bool search(const std::string &s) {
        return search(root_, s, 0);
    }

private:
    struct Node {
        explicit Node(char ch) : current(ch), leaf(false) {
            children_node.resize(26);
        }

        char current;
        bool leaf;
        std::vector<std::shared_ptr<Node>> children_node;
    };

    bool search(std::shared_ptr<Node> root, const std::string &s, int index) {
        if (!root) {
            return false;
        }
        if (index == s.size()) {
            return root->leaf;
        }
        if (s[index] != '.') {
            int child_index = s[index] - 'a';
            return search(root->children_node[child_index], s, index + 1);
        }
        for (auto &&node: root->children_node) {
            if (search(node, s, index + 1)) {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<Node> root_;
};

TEST(leetcode, 211) {
    WordDictionary dictionary;
    dictionary.addWord("bad");
    dictionary.addWord("dad");
    dictionary.addWord("mad");
    ASSERT_FALSE(dictionary.search("pad"));
    ASSERT_TRUE(dictionary.search("bad"));
    ASSERT_TRUE(dictionary.search(".ad"));
    ASSERT_TRUE(dictionary.search("b.."));
}