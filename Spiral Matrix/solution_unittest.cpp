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
            "input": [
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]
            ],
            "want": [1, 2, 3, 6, 9, 8, 7, 4, 5]
        },
        {
            "input": [
                [1, 2, 3, 4],
                [5, 6, 7, 8],
                [9, 10, 11, 12]
            ],
            "want": [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
        },
        {
            "input": [
                [1, 2, 3, 4, 5],
                [6, 7, 8, 9, 10],
                [11, 12, 13, 14, 15]
            ],
            "want": [1, 2, 3, 4, 5, 10, 15, 14, 13, 12, 11, 6, 7, 8, 9]
        },
        {
            "input": [
                [1]
            ],
            "want": [1]
        },
        {
            "input": [],
            "want": []
        }
    ]
    )"_json;
    for (json::iterator test = tests.begin(); test != tests.end(); ++test)
    {
        vector<vector<int>> matrix = getMatrixfromJson<int>((*test)["input"]);
        vector<int> output = s.spiralOrder(matrix);
        // prettyPrintVector(output);
        EXPECT_STREQ((*test)["want"].dump().c_str(),
                     json(output).dump().c_str());
    }
}
