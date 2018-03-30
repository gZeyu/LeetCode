#include <iostream>
#include <string>
using namespace std;

//Manacher’s algorithm
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int len = 2 * s.length() + 3;
        char *t = new char[len]();
        t[0] = -1;
        t[1] = '#';
        for (int i = 0; i < s.length(); i++)
        {
            t[2 * i + 2] = s[i];
            t[2 * i + 3] = '#';
        }

        int *p = new int[len]();
        int c = 0, r = 0, j = 0, maxP = 0, cur = 1;
        for (int i = 1; i < len - 1; ++i)
        {
            if (i < r)
            {
                j = 2 * c - i;
                p[i] = (p[j] < r - i) ? p[j] : r - i;
            }
            while (t[i + p[i] + 1] == t[i - p[i] - 1])
            {
                p[i]++;
            }
            if (i + p[i] >= r)
            {
                c = i;
                r = i + p[i];
            }
            if (p[i] > maxP)
            {
                maxP = p[i];
                cur = i;
            }
        }
        delete[] t;
        delete[] p;
        return s.substr((cur - maxP - 1) / 2, maxP);
    }
};
