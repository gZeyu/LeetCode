#include <iostream>
#include <string>
#include <limits.h>
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
    int myAtoi(string str)
    {
        string::iterator iter = str.begin();

        int num = 0;
        while (*iter == ' ' && *iter != '\0')
        {
            ++iter;
        }
        if (*iter == '\0')
        {
            return 0;
        }
        int sign = 1;
        if (*iter == '+')
        {
            ++iter;
        }
        else if (*iter == '-')
        {
            ++iter;
            sign = -1;
        }
        while (*iter >= '0' && *iter <= '9')
        {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && *iter - '0' > 7))
            {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + *iter - '0';
            ++iter;
        }
        return sign * num;
    }
};