#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    Solution s;
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> b(a, a + 5);
    EXPECT_EQ(6, s.maxArea(b));
}

TEST(SolutionTest, Zero)
{
    Solution s;
    vector<int> b;
    EXPECT_EQ(0, s.maxArea(b));
}