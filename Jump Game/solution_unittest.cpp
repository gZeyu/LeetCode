#include "solution.cpp"
#include "utils/utils.h"
#include "gtest/gtest.h"
#include <limits.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

TEST(SolutionTest, Positive)
{
    Solution s;
    json tests = R"(
    [{
            "input": [2, 3, 1, 1, 4],
            "want": true
        },
        {
            "input": [3, 2, 1, 0, 4],
            "want": false
        },
        {
            "input": [1],
            "want": true
        },
        {
            "input": [0],
            "want": true
        }
    ]
    )"_json;
    for (json::iterator test = tests.begin(); test != tests.end(); ++test)
    {
        vector<int> nums = getVectorfromJson<int>((*test)["input"]);
        bool want = (*test)["want"];
        bool output = s.canJump(nums);
        EXPECT_EQ(want, output);
    }
}
