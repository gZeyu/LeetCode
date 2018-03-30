#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    Solution s;
    EXPECT_STREQ("bab", s.longestPalindrome("babad").c_str());
    EXPECT_STREQ("bb", s.longestPalindrome("cbbd").c_str());
    EXPECT_STREQ("cdzdc", s.longestPalindrome("abcdzdcab").c_str());
}