#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
const int M = 1002;
long long dp[N][M];
int val[N], wt[N];

long long knapsack(int n, int cap)
{

    if (n == 0)
        return 0;

    if (dp[n][cap] != -1)
        return dp[n][cap];

    if (cap < wt[n])
        return dp[n][cap] = knapsack(n - 1, cap);

    long long ans1 = 0, ans2;
    if (cap >= wt[n])
    {
        ans1 = val[n] + knapsack(n, cap - wt[n]);
    }
    ans2 = knapsack(n - 1, cap);

    return dp[n][cap] = max(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << knapsack(n, k) << endl;

    return 0;
}