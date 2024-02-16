//Problem link: https://lightoj.com/problem/coin-change-i

/*
- state: dp(n, K) -> number of ways to make sum = K from coin 1 to n without crossing limit
- recurrance: dp(n, K) -> dp(n - 1, K) +
                          dp(n - 1, K - coin[n]) +
                          dp(n - 1, K - 2 * coin[n]) +
                          .....
                          dp(n - 1, K - limit[n] * coin[n]) +
- base_case: dp(0, 0) = 1
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 100000007;

int dp[N][M];
int coin[N], limit[N];

int coin_change(int n, int K){
    if(n == 0) {
        if(K == 0) return 1;
        return 0;
    }

    if(dp[n][K] != -1) return dp[n][K];

    int ans = coin_change(n - 1, K);

    for(int i = 1; i <= limit[n]; i++) {
        if(K - i * coin[n] < 0) break;

        int ret = coin_change(n - 1, K - i * coin[n]);
        ans = (ans + ret) % MOD;
    }

    return dp[n][K] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t, tst = 0;
    cin >> t;
    while (t--)
    {
        int n, K;
        cin >> n >> K;

        for (int i = 1; i <= n; i++) cin >> coin[i];
        for (int i = 1; i <= n; i++) cin >> limit[i];
        
        memset(dp, -1, sizeof(dp));

        int ans = coin_change(n, K);
        cout << "Case " << ++tst << ": " << ans << "\n";
    }
    
    return 0;
}