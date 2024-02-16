// Problem link: https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;

string s, t;
const int N = 3005;
const int M = 3005;

int dp[N][M];

int LCS(int i, int j)
{
    // Base case
    if (i == s.size() or j == t.size())
        return 0;

    // if answer is already calculated then return it
    if (dp[i][j] != -1)
    {

        return dp[i][j];
    }

    // calculate result from smaller sub-problems
    if (s[i] == t[j])
    {
        int ans = 1 + LCS(i + 1, j + 1);
        dp[i][j] = ans;
        return ans;
    }
    int ans = max(LCS(i + 1, j), LCS(i, j + 1));
    return dp[i][j] = ans;
}

int main()
{
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    
    LCS(0, 0);

    string ans;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            ans += s[i];
            i++, j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1]) i++;
        else j++;
    }

    cout << ans << endl;
    return 0;
}
