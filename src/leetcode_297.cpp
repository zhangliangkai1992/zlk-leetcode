/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-07-09 20:41
 */
#include <gtest/gtest.h>

#include <algorithm>
#include <stack>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x = 0, TreeNode* left = nullptr,
                    TreeNode* right = nullptr)
      : val(x), left(left), right(right) {}
};

class Codec {
  const char SPLITER = ' ';
  const std::string EMPTY_NODE = "#";
  void buildString(TreeNode* root, std::ostringstream* poss) {
    auto& oss = *poss;
    if (!root) {
      oss << EMPTY_NODE << SPLITER;
    } else {
      oss << root->val << SPLITER;
      buildString(root->left, poss);
      buildString(root->right, poss);
    }
  }
  TreeNode* buildTree(std::vector<std::string>* preOrder) {
    auto back = preOrder->back();
    preOrder->pop_back();
    if (back == EMPTY_NODE) {
      return nullptr;
    }
    auto root = new TreeNode(std::stoi(back));
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
  }

 public:
  std::string serialize(TreeNode* root) {
    std::ostringstream oss;
    buildString(root, &oss);
    return oss.str();
  }

  TreeNode* deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::vector<std::string> preOrder;
    std::string str;
    while (iss >> str) {
      preOrder.push_back(str);
    }
    std::reverse(preOrder.begin(), preOrder.end());
    return buildTree(&preOrder);
  }
};
TEST(leetcode297, 1) {
  std::string data = "1 2 # # 3 4 # # 5 # # ";
  auto root = Codec().deserialize(data);
  auto res = Codec().serialize(root);
  ASSERT_EQ(data, res);
}
