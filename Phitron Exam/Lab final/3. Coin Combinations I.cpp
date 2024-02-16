// Problem link: https://cses.fi/problemset/task/1635
// Tabulation:

#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, x, ans;
    cin >> n >> x;

    vector<long long>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        ans = 0;
        for (int j = 0; j < n; j++)
        {
            if(i - arr[j] >= 0) 
            {
                ans += dp[i - arr[j]];
            }
        }
        dp[i] = ans %  MOD;
    }

    cout << dp[x] << endl;

    return 0;
}