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

int stone_2(int n){
    if(n == 1) return 0;

    if(dp[n] != -1) return dp[n];

    int ans = INF;

    for (int i = 1; i <= k; i++)
    {
        if(n <= 0){
            break;
        }
        int candidate_ans = stone_2(n - i) + abs(h[n] - h[n - i]);
        ans = min(ans, candidate_ans);
    }

    dp[n] = ans;
    return ans;
    
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    
    memset(dp, -1, sizeof(dp));

    cout << stone_2(n) << endl;
    return 0;

}