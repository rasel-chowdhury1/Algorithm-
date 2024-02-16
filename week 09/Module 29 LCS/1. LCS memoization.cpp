//LSC -> Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

string s, t;
const int N = 101;
const int M = 1001;

int dp[N][M];

int LCS(int i, int j)
{
    //Base case
    if(i == s.size() or j == t.size()) return 0;

    //if answer is already calculated then return it
    if(dp[i][j] != -1) return dp[i][j];

    //calculate result from smaller sub-problems
    int ans1 = 0, ans2 = 0;
    if(s[i] == t[j]) ans1 = 1 + LCS(i + 1, j + 1);
    else ans2 = max(LCS(i + 1, j), LCS(i, j + 1));

    int ans = max(ans1, ans2);
    return dp[i][j] = ans;
}

/*
abyx abxy
*/

int main()
{
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));

    int ans = LCS(0, 0);

    cout << ans << endl;

    return 0;
}