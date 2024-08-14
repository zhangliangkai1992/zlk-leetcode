/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/14 09:33
 */
#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
    struct TrieNode {
        char ch;
        bool leaf;
        std::vector<std::shared_ptr<TrieNode>> children;

        explicit TrieNode(char c) : ch(c), leaf(false), children(26, nullptr) {}
    };

    std::shared_ptr<TrieNode> ConstructTree(const std::vector<std::string> &words) {
        std::shared_ptr<TrieNode> root(new TrieNode('\0'));
        for (auto &&word: words) {
            auto p = root;
            for (auto &&ch: word) {
                auto index = ch - 'a';
                if (p->children[index] == nullptr) {
                    p->children[index].reset(new TrieNode(ch));
                }
                p = p->children[index];
            }
            p->leaf = true;
        }
        return root;
    }

    void dfs(std::shared_ptr<TrieNode> root, std::vector<std::string> *found_words, std::string *current,
             const std::vector<std::vector<char>> &board, int row, int col, std::vector<std::vector<bool>> *visited) {
        if ((*visited)[row][col]) {
            return;
        }
        current->push_back(board[row][col]);
        (*visited)[row][col] = true;
        auto child = root->children[board[row][col] - 'a'];
        if (child == nullptr) {
            current->pop_back();
            (*visited)[row][col] = false;
            return;
        }
        if (child->leaf) {
            found_words->push_back(*current);
            child->leaf = false;
        }
        if (row > 0) {
            dfs(child, found_words, current, board, row - 1, col, visited);
        }
        if (row < board.size() - 1) {
            dfs(child, found_words, current, board, row + 1, col, visited);
        }
        if (col > 0) {
            dfs(child, found_words, current, board, row, col - 1, visited);
        }
        if (col < board[row].size() - 1) {
            dfs(child, found_words, current, board, row, col + 1, visited);
        }
        current->pop_back();
        (*visited)[row][col] = false;
    }

public:
    std::vector<std::string>
    findWords(const std::vector<std::vector<char>> &board, const std::vector<std::string> &words) {
        auto root = ConstructTree(words);
        std::vector<std::string> found_words;
        std::string current;
        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                dfs(root, &found_words, &current, board, i, j, &visited);
            }
        }
        return found_words;
    }
};

TEST(leetcode, 212) {
    std::vector<std::vector<char>> board = {{'o', 'a', 'a', 'n'},
                                            {'e', 't', 'a', 'e'},
                                            {'i', 'h', 'k', 'r'},
                                            {'i', 'f', 'l', 'v'}};
    std::vector<std::string> words = {"oath", "pea", "eat", "rain"};
    std::vector<std::string> expect = {"oath", "eat"};
    auto res = Solution().findWords(board, words);
    ASSERT_EQ(res.size(), expect.size());
    for (int i = 0; i < res.size(); ++i) {
        ASSERT_EQ(res[i], expect[i]);
    }
}