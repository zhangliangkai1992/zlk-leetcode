/**
 * @Copyright (c) 2023 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2023-03-18 23:10
 */

#include <include/leetcode_util.h>

#include <stack>
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::stack<TreeNode *> st;
    auto p = root;
    std::vector<int> res;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        res.push_back(st.top()->val);
        p = st.top()->right;
        st.pop();
      }
    }
    return res;
  }
};

TEST(leetcode, 94) {
  std::vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  auto root = buildTree(preOrder, inOrder);
  auto res = Solution().inorderTraversal(root);
  AssertVector(inOrder, res);
  FreeTree(root);
}
