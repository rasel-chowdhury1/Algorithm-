//Problem link: https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

/*
    1. state: knapsack(n, cap) -> maximum profit considering objects 1 to n and capacity = cap
    2. recurrance:
        knapsack(n, cap) -> max{
                                val[n] + knapsack(n - 1, cap - wt[n]), knapsack(n - 1, cap)
                            }
    3. base case: knapsack(0, x) = 0
*/
const int N = 102;
const int M = 1e5 + 5;
long long dp[N][M];
int val[N], wt[N];

long long knapsack(int n, int cap){
    //1. base case
    if(n == 0) return 0;

    //2. if result is already calculated for this state return it
    if(dp[n][cap] != -1) return dp[n][cap];

    //3. calculate result from smaller sub-problem

    if(cap < wt[n]) return dp[n][cap] = knapsack(n - 1, cap);
    

    long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
    long long ans2 = knapsack(n - 1, cap);

    return dp[n][cap] = max(ans1, ans2);
    
}
int main()
{
    int n, cap;
    cin >> n >> cap;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n, cap) << endl;

    return 0;
}