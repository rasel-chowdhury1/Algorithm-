#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = min(
                            stone(n - 1) + abs(h[n] - h[n - 1])
                            stone(n - 2) + abs(h[n] - h[n - 2])
                        )
- base case: stone(1) = 0
*/
int h[N];
int dp[N];

int stone(int n){
    //1. base case
    if(n == 1) return 0;

    //2. if answer is already solved, then return
    if(dp[n] != -1) return dp[n];

    //2. calculate the answer from smaller sub-problems
    int ans1 = stone(n - 1) + abs(h[n] - h[n - 1]);

    //corner case:
    if(n == 2){
        dp[n] = ans1;
        return ans1;
    }

    int ans2 = stone(n - 2) + abs(h[n] - h[n - 2]);
    int ans = min(ans1, ans2);
    dp[n] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> h[i];

    memset(dp, -1, sizeof(dp));

    cout << stone(n) << endl;
    return 0;
}


/*
I->
6
30 10 60 10 60 50

O -> 40
*/