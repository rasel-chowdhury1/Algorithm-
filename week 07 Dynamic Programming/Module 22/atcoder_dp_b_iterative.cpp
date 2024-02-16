#include <bits/stdc++.h>
using namespace std;

/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: state(n) = for i = 1 to k:
                            min(
                                stone(n - i) + abs(h[n] - h[n - i])
                            )
- base case: stone(1) = 0
*/

const int N = 1e5 + 5;
const int INF = 2e9;
int h[N], dp[N];
int n, k;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;
        for(int j = 1; j <= k; j++){
            if(i - j <= 0){
                break;
            }
            int candidate_ans = dp[i - j] + abs(h[i] - h[i - j]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }
    cout << dp[n] << endl;
    return 0;
}