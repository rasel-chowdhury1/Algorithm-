//Problem link - https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>>grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    vector<vector<ll>>dp(n + 5, vector<ll>(m + 5, -1));
    dp[0][0] = 1;
   
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int ans = 0;
            if(i == 0 and j == 0) continue;

            if(i > 0 and grid[i][j] != '#') ans+= dp[i - 1][j] % MOD;
            if(j > 0 and grid[i][j] != '#') ans += dp[i][j - 1] % MOD;

            dp[i][j] = ans % MOD;
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    
    return 0;
}