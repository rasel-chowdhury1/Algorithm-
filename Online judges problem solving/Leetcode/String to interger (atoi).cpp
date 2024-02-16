#include <bits/stdc++.h>
using namespace std;

/*

NOT ACCEPTED--

*/
class Solution
{
public:
    long long MAXX = 2147483647;
    long long MINN = -2147483646;
    int myAtoi(string s)
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i < n && s[i] == '+')
        {
            sign = 1;
            i++;
        }

        if (i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }

        while (i < n && s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            if (result > MAXX / 10 || (result == MAXX / 10) && s[i] - '0' > MAXX % 10)
            {
                return result = (sign == 1 ? MAXX : MINN);
            }
            result = result * 10 + s[i] - '0';
            i++;
        }

        return result * sign;
    }
};

int main()
{
    string s = "+-12";
    Solution sl;
    cout << sl.myAtoi(s);
}