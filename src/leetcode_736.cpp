/**
 * @Copyright (c) 2021 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2021-09-14 22:18
 */

#include <gtest/gtest.h>

class Solution {
  int findLastExpr(const std::string &expr) {
    auto sz = expr.size();
    if (expr[sz - 2] != ')') {
      return expr.find_last_of(' ') + 1;
    }
    int index = sz - 3;
    int diff = 1;
    while (diff) {
      if (expr[index] == '(') {
        --diff;
      } else if (expr[index] == ')') {
        ++diff;
      }
      --index;
    }
    return index + 1;
  }
  int findExprEnd(const std::string &expr, int start) {
    if (expr[start] != '(') {
      return expr.find(' ', start) - 1;
    }
    int index = start + 1;
    int diff = 1;
    while (diff) {
      if (expr[index] == '(') {
        ++diff;
      } else if (expr[index] == ')') {
        --diff;
      }
      ++index;
    }
    return index - 1;
  }
  int eval(const std::string &expr,
           const std::unordered_map<std::string, int> &env) {
    if (expr[0] != '(') {
      if (expr[0] >= '0' && expr[0] <= '9' || expr[0] == '-') {
        return std::stoi(expr);
      }
      return env.at(expr);
    }

    auto pos = findLastExpr(expr);
    auto rightExpr = expr.substr(pos, expr.size() - pos - 1);
    if (expr.substr(1, 3) == "add") {
      auto leftExpr = expr.substr(5, pos - 6);
      return eval(leftExpr, env) + eval(rightExpr, env);
    }

    if (expr.substr(1, 4) == "mult") {
      auto leftExpr = expr.substr(6, pos - 7);
      return eval(leftExpr, env) * eval(rightExpr, env);
    }

    std::unordered_map<std::string, int> newEnv = env;
    for (int i = 5; i < pos;) {
      auto nextPos = expr.find(' ', i);
      auto variable = expr.substr(i, nextPos - i);
      auto exprEnd = findExprEnd(expr, nextPos + 1);
      auto letExpr = expr.substr(nextPos + 1, exprEnd - nextPos);
      newEnv[variable] = eval(letExpr, newEnv);
      i = exprEnd + 2;
    }
    return eval(rightExpr, newEnv);
  }

 public:
  int evaluate(const std::string &expr) {
    std::unordered_map<std::string, int> env;
    return eval(expr, env);
  }
};

TEST(leetcode, 736) {
  std::string expr =
      "(let a (add 1 2) b (mult a 3) c 4 d (add a b) (mult d d))";
  ASSERT_EQ(Solution().evaluate(expr), 144);
}
