#include <iostream>
#include <vector>
#include "utils/utils.h"
using namespace std;

static int any = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

// Dynamic Programming Bottom-up
// class Solution
// {
//   public:
//     bool canJump(vector<int> &nums)
//     {
//         vector<bool> reachable(nums.size(), false);
//         int length = nums.size();
//         reachable[length - 1] = true;
//         for (int i = length - 2; i > -1; --i)
//         {
//             int furthest = (i + nums[i] <= length - 1) ? i + nums[i] : length - 1;
//             for (int j = furthest; j > i; --j)
//             {
//                 if (reachable[j] == true)
//                 {
//                     reachable[i] = true;
//                     break;
//                 }
//             }
//         }
//         return reachable[0];
//     }
// };
// Greedy
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i + nums[i] >= lastPos)
            {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
