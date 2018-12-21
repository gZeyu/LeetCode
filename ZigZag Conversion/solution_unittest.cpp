#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    Solution s;

    EXPECT_STREQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3).c_str());
    EXPECT_STREQ("PINALSIGYAHRPI", s.convert("PAYPALISHIRING", 4).c_str());

    EXPECT_STREQ("A", s.convert("A", 1).c_str());
}