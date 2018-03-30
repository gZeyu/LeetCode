#include <iostream>
#include <string>
using namespace std;

//Manacher’s algorithm
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string t;
        for (int i = 0; i < s.length(); i++)
        {
            t = t + "#" + s[i];
        }
        t += "#";

        int *p = new int[t.length()]();
        p[0] = 0;
        p[1] = 1;
        int c = 1, r = 2, j = 0, maxP = 0, cur = 0;
        for (int i = 2; i < t.length(); ++i)
        {
            j = 2 * c - i;

            if (p[j] < r - i)
            {
                p[i] = p[j];
            }
            else
            {
                p[i] = (r > i) ? (r - i) : 0;
                while ((t[i + p[i] + 1] == t[i - p[i] - 1]) && (i - p[i] - 1 >= 0))
                {
                    p[i]++;
                }
                c = i;
                r = i + p[i];
            }
            if (p[i] > maxP)
            {
                maxP = p[i];
                cur = i;
            }
        }
        delete[] p;
        return s.substr((cur - maxP + 1) / 2, maxP);
    }
};
