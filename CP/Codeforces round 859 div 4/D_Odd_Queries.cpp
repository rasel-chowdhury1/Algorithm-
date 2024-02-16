/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vll vector<ll>
#define endl "\n"
using namespace std;
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), pre(n, 0);
    ll sm = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sm += v[i];
    }
    pre[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = v[i] + pre[i - 1];
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        ll kss = pre[r - 1] - (pre[l - 1] - v[l - 1]);
        ll nsm = sm - kss + (r - l + 1) * k;
        if (nsm % 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}