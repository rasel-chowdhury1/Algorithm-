/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string ans, temp = number;
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == digit)
            {
                temp.erase(temp.begin() + i);
                ans = max(ans, temp);
                temp = number;
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;

    string str = "123";
    char digit = '3';

    string temp = str;

    string ans = s.removeDigit(str, digit);

    cout << ans << "\n";

    return 0;
}