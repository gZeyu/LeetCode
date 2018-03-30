#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        /* clang-format off */
        std::vector< vector<char> > buff(numRows);
        /* clang-format on */
        // if (numRows == 1)
        // {
        //     return s;
        // }
        // int i = 0, j = 0;
        // while (i < s.size())
        // {
        //     j = i % (2 * numRows - 2);
        //     if (j < numRows)
        //     {
        //         buff[j].push_back(s[i]);
        //     }
        //     else
        //     {
        //         buff[(2 * numRows - 2) - j].push_back(s[i]);
        //     }
        //     ++i;
        // }
        int i = 0, len = s.size();
        while (i < len)
        {
            for (int j = 0; j < numRows && i < len; ++j)
            {
                buff[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j > 0 && i < len; --j)
            {
                buff[j].push_back(s[i++]);
            }
        }
        string t;
        for (int i = 0; i < numRows; ++i)
        {
            t += string(buff[i].begin(), buff[i].end());
        }
        return t;
    }
};
