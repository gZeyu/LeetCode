/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.79%)
 * Total Accepted:    314.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> set;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i)
        {
            int j = i + 1, k = len - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    set.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        --k;
                    }
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
                while (i < len - 2 && nums[i + 1] == nums[i])
                    i++;
            }
        }
        return set;
    }
};