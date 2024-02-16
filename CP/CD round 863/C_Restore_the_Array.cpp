/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    n--;
    vector<ll> v(n), a(n + 1);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    a[0] = v[0];
    a[n] = v[n - 1];
    for (ll i = 0; i < n - 1; i++)
        a[i + 1] = min(v[i], v[i + 1]);
    for (ll i = 0; i < n + 1; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}