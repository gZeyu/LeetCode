#include <iostream>
#include <vector>
#include <map>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> find;
        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            if (find.count(diff))
            {
                return {i, find[diff]};
            }
            find[nums[i]] = i;
        }
        return {};
    }
};