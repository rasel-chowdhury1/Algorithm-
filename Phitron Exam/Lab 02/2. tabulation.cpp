#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        vector<long long int> arr(n);
        vector<long long int> dp(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        dp[0] = arr[0];
        dp[1] = max(dp[0], arr[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        cout << "Case " << i << ": ";
        cout << dp[n - 1] << endl;
    }

    return 0;
}
