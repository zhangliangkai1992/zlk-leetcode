/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-18 23:16
 */

#include <include/leetcode_util.h>

#include <stack>

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::stack<TreeNode *> st;
    auto p = root;
    std::vector<int> res;
    while (p || !st.empty()) {
      if (p) {
        res.push_back(p->val);
        st.push(p);
        p = p->right;
      } else {
        p = st.top()->left;
        st.pop();
      }
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

TEST(leetcode, 145) {
  std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().postorderTraversal(root);
  std::vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};
  AssertVector(postOrder, res);
  FreeTree(root);
}
