#include <limits.h>
#include "solution.cpp"
#include "gtest/gtest.h"

TEST(SolutionTest, Positive)
{
    Solution s;
    EXPECT_STREQ("MMMCMXCIX", s.intToRoman(3999).c_str());
    EXPECT_STREQ("MDCCCXCIX", s.intToRoman(1899).c_str());
    EXPECT_STREQ("I", s.intToRoman(1).c_str());
    EXPECT_STREQ("XCVIII", s.intToRoman(98).c_str());
    EXPECT_STREQ("CMXCIX", s.intToRoman(999).c_str());
}
