/**
 * @Copyright (c) 2024 The Authors All rights reserved
 * @Author: zhangliangkai
 * @create: 2024/8/12 21:57
 */
#include <gtest/gtest.h>
#include <sstream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(const std::string &path) {
        std::istringstream iss(path);
        std::stack<std::string> path_stack;
        std::string current_name;
        while (std::getline(iss, current_name, '/')) {
            if (current_name.empty() || current_name == ".") {
                continue;
            } else if (current_name == "..") {
                if (!path_stack.empty()) {
                    path_stack.pop();
                }
            } else {
                path_stack.push(current_name);
            }
        }
        std::vector<std::string> path_vec;
        while (!path_stack.empty()) {
            path_vec.emplace_back(path_stack.top());
            path_stack.pop();
        }
        std::string abs_path = "/";
        for (auto it = path_vec.rbegin(); it != path_vec.rend(); ++it) {
            abs_path += *it + "/";
        }
        if (abs_path.size() > 1) {
            abs_path.resize(abs_path.size() - 1);
        }
        return abs_path;
    }
};

TEST(leetcode, 71) {
    std::string path = "/home/";
    std::string abs_path = "/home";
    EXPECT_EQ(Solution().simplifyPath(path), abs_path);
}