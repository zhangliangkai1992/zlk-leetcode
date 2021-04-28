#include <gtest/gtest.h>
int add(int a, int b) {
	return a + b;
}

TEST(leetcode, demo) {
	EXPECT_EQ(add(3,4), 7);
}
