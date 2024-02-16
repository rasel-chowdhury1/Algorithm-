//Problem link - https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n ;

    vector<vector<char>>grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    vector<vector<ll>>dp(n + 5, vector<ll>(n + 5, -1));
    if(grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
   
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int ans = 0;
            if(i == 0 and j == 0) continue;

            if(i > 0 and grid[i][j] != '*') ans+= dp[i - 1][j] % MOD;
            if(j > 0 and grid[i][j] != '*') ans += dp[i][j - 1] % MOD;

            dp[i][j] = ans % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}