#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 10;
vector<long long> a(N, 0);
vector<long long> dp(N, -1);

long long f(int n)
{
    if(n < 1) return 0;

    long long &x = dp[n];
    if(x != -1) return x;

    x = max(f(n - 1), f(n - 2) + a[n] * n);

    return x;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }

    cout << f(100000) << endl;
    return 0;
}
