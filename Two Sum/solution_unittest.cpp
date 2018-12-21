#include <limits.h>
#include <vector>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{

    int a[] = {2, 7, 11, 15};
    int b[] = {0, 1};
    vector<int> nums(a, a + 4);
    int target = 9;
    vector<int> ans(b, b + 2);

    Solution s;
    EXPECT_EQ(s.twoSum(nums, target), ans);
}
