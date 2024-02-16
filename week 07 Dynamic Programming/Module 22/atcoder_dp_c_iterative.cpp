// Problem link: https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- state: fun(n, x) -> maximum happiness till day-n
                    if we pick task-x on day n

- recurrance: fun(n, x) = max{
                            fun(n - 1, y) where x != y
                            + hapiness[n][x]
                        }

- base case: fun(1, x) = happiness[n][x]
*/

int happiness[N][4], dp[N][4];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        dp[1][i] = happiness[1][i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int max_profit = -1;

            for (int k = 1; k <= 3; k++)
            {
                if (k != j)
                {
                    int candidate_profit = dp[i - 1][k] + happiness[i][j];
                    max_profit = max(max_profit, candidate_profit);
                }
            }
            dp[i][j] = max_profit;
        }
    }

    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << endl;
    return 0;
}