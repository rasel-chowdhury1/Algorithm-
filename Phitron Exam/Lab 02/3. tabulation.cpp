#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
long long int dp[N];
long long int dp2[N];

int main()
{
    int n, m = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        dp[b]++;
    }

    dp2[0] = 0;
    dp2[1] = dp[1];

    for (int i = 2; i <= 100000; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + i * dp[i]);
    }

    cout << dp2[100000] << endl;
    return 0;
}
