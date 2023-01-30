//
// Created by zlk on 11/13/22.
//


#include <gtest/gtest.h>

class Solution {
public:
    int lengthLongestPath(const std::string &input) {
        std::istringstream iss(input);
        std::string line;
        std::unordered_map<int, int> pathLen;
        int res = 0;
        while (std::getline(iss, line, '\n')) {
            int tabs = 0;
            while (tabs < line.size() && line[tabs] == '\t')++tabs;
            if (tabs == 0) {
                pathLen[tabs] = line.size();
            } else {
                pathLen[tabs] = pathLen[tabs - 1] + 1 + line.size() - tabs;
            }
            if (line.find('.') != std::string::npos) {
                res = std::max(res, pathLen[tabs]);
            }
        }
        return res;
    }
};

TEST(leetcode, 388) {
    std::string input("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    int res = 20;
    ASSERT_EQ(Solution().lengthLongestPath(input), res);
}
