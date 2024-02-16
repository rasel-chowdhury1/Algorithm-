//Problem link: https://atcoder.jp/contests/dp/tasks/dp_c
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

int fun(int n, int x)
{
    if(n == 1) return happiness[n][x];

    if(dp[n][x] != -1) return dp[n][x];

    int max_profit = -1;

    for (int i = 1; i <= 3; i++)
    {
        if(x != i)
        {
            int candidate_profit = fun(n - 1, i) + happiness[n][x];
            max_profit = max(max_profit, candidate_profit);
        }
    }

    dp[n][x] = max_profit;
    return max_profit;
    
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans_1 = fun(n, 1);
    int ans_2 = fun(n, 2);
    int ans_3 = fun(n, 3);

    cout << max({ans_1, ans_2, ans_3}) << endl;
    return 0;
    
}