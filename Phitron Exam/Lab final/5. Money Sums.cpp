// Problem link: https://cses.fi/problemset/task/1745
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = sum; j >= arr[i]; j--)
            dp[j] = dp[j] | dp[j - arr[i]];

    // cout << dp.size() << "\n";
    int count = 0;
    for (int i = 1; i <= sum; i++)
        if (dp[i]) count++;

    cout << count << "\n";

    for (int i = 1; i <= sum; i++)
        if (dp[i])  cout << i << " ";

    return 0;
}
