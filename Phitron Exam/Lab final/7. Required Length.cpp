//Problem link: https://codeforces.com/contest/1681/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> mp;
ll solve(ll n, ll x)
{
    int len = to_string(x).size();

    if (len == n)
        return 0;
    if (mp.count(x) > 0)
        return mp[x];

    ll &res = mp[x] = 1e9;
    ll nSize = x;

    while (nSize > 0)
    {
        if (nSize % 10 > 1)
            res = min(res, 1 + solve(n, x * (nSize % 10)));
        nSize /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x;
    cin >> n >> x;

    if (solve(n, x) != 1e9)
        cout << solve(n, x) << endl;
    else
        cout << -1 << endl;
    return 0;
}