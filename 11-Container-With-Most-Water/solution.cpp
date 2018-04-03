#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, k = 0;
        int max = 0, tmp = 0;
        while (i < j)
        {
            tmp = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            max = (tmp > max) ? tmp : max;
            if (height[i] < height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return max;
    }
};