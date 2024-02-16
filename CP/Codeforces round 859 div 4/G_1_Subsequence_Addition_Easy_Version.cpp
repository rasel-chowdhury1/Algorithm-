
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define SIZE 1e6 + 2
#define endl "\n"

void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    ll sm = 1;
    if (v[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (ll i = 1; i < n; i++)
    {
        if (v[i] <= sm)
        {
            sm += v[i];
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}