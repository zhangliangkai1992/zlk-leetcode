/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-08-08 17:10
 */

#include <gtest/gtest.h>

#include <stack>

class Solution {
  int applyCalc(int a, int b, char op) {
    switch (op) {
      case '-':
        return a - b;
      case '+':
        return a + b;
      case '*':
        return a * b;
    }
    return 0;
  }
  void calc(const std::vector<int>& nums, const std::vector<char>& ops,
            int curOpIndex, std::stack<int>* numSt, std::stack<char>* opSt,
            std::vector<int>* res) {
    if (curOpIndex == ops.size() && numSt->size() == 1 && opSt->empty()) {
      res->push_back(numSt->top());
      return;
    }
    if (curOpIndex < ops.size()) {
      auto cpNum = *numSt;
      auto cpOp = *opSt;
      cpNum.push(nums[curOpIndex + 1]);
      cpOp.push(ops[curOpIndex]);
      calc(nums, ops, curOpIndex + 1, &cpNum, &cpOp, res);
    }
    if (opSt->empty()) return;
    auto b = numSt->top();
    numSt->pop();
    auto a = numSt->top();
    numSt->pop();
    auto op = opSt->top();
    opSt->pop();
    numSt->push(applyCalc(a, b, op));
    calc(nums, ops, curOpIndex, numSt, opSt, res);
  }

 public:
  std::vector<int> diffWaysToCompute(const std::string& exp) {
    // 给定入栈顺序，求所有的出栈顺序
    // 入栈（+-*), 出栈(计算)
    std::vector<int> nums;
    std::vector<char> ops;
    int start = 0;
    auto sz = exp.size();
    for (int i = 0; i <= sz; ++i) {
      if (i == sz || '+' == exp[i] || '-' == exp[i] || '*' == exp[i]) {
        nums.push_back(std::stoi(exp.substr(start, i - start)));
        if (i < sz) {
          ops.push_back(exp[i]);
        }
        start = i + 1;
      }
    }
    std::stack<int> numSt;
    numSt.push(nums[0]);
    std::stack<char> opSt;
    std::vector<int> res;
    calc(nums, ops, 0, &numSt, &opSt, &res);
    return res;
  }
};

TEST(leetcode241, 1) {
  auto exp = "2-1-1";
  auto res = Solution().diffWaysToCompute(exp);
  decltype(res) expect = {2, 0};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
