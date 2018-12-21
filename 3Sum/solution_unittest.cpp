#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    vector<int> nums;
    vector<vector<int>> set;
    Solution s;

    nums = {-1, 0, 1, 2, -1, -4};
    set = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(s.threeSum(nums), set);
    nums = {-1, 1, 0};
    set = {{-1, 0, 1}};
    EXPECT_EQ(s.threeSum(nums), set);
    nums = {1, 0, -1, -1, -1, -1, 0, 1, 1, 1};
    set = {{-1, 0, 1}};
    EXPECT_EQ(s.threeSum(nums), set);
    nums = {0, 0, 0, 0, 1, 3};
    set = {{0, 0, 0}};
    EXPECT_EQ(s.threeSum(nums), set);
}
