#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int main()
{
    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        if (i % 3 == 0) dp[i] = 1 + dp[i / 3];
        else if (i % 3 == 1) dp[i] = 1 + dp[i - 1];
        else if (i % 2 == 0) dp[i] = 1 + dp[i / 2];
        else dp[i] = 1 + dp[i - 1];
    }

    cout << dp[n] << endl;
    return 0;
}