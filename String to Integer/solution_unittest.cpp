#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    Solution s;

    EXPECT_EQ(0, s.myAtoi(" "));
    EXPECT_EQ(0, s.myAtoi(""));
    EXPECT_EQ(0, s.myAtoi(","));
    EXPECT_EQ(123, s.myAtoi("123"));
    EXPECT_EQ(123, s.myAtoi("  123"));
    EXPECT_EQ(123, s.myAtoi("123,456"));
    EXPECT_EQ(123, s.myAtoi("+123"));
    EXPECT_EQ(-123, s.myAtoi("-123"));
    EXPECT_EQ(123, s.myAtoi("0000123"));
    EXPECT_EQ(2147483647, s.myAtoi("2147483649"));
    EXPECT_EQ(2147483647, s.myAtoi("1234566789123456789"));
    EXPECT_EQ(-2147483648, s.myAtoi("-2147483649"));
    EXPECT_EQ(-2147483648, s.myAtoi("-1234566789123456789"));
}