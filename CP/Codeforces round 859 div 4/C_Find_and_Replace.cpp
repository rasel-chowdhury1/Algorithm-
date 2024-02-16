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
    string s;
    cin >> s;
    map<char, ll> mp;
    map<char, vector<ll>> mp2;
    for (auto x : s)
        mp[x]++;
    for (ll i = 0; i < n; i++)
    {
        mp2[s[i]].push_back(i);
    }
    ll sz = mp.size();
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (sz == 1)
    {
        if (n > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return;
    }
    else if (sz == 2)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        if (sz == n)
        {
            cout << "YES" << endl;
            return;
        }
        for (auto x : mp2)
        {
            vector<ll> temp = x.second;
            ll ff = temp[0];
            for (ll i = 1; i < temp.size(); i++)
            {
                if ((ff % 2 != 0 and temp[i] % 2 == 0) or (ff % 2 == 0 and temp[i] % 2 != 0))
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        cout << "YES" << endl;
        return;
    }
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