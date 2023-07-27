/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-14 00:55
 */

#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> st;
    auto p = root;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        res.push_back(p->val);
        p = p->left;
      } else {
        p = st.top()->right;
        st.pop();
      }
    }
    return res;
  }
};

TEST(leetcode, 144) {
  std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().preorderTraversal(root);
  AssertVector(preOrder, res);
  FreeTree(root);
}
