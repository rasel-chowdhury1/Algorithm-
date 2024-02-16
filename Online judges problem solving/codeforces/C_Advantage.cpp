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
    ll n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> v1 = v;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v1[i] == v[n - 1])
        {
            cout << (v1[i] - v[n - 2]) << " ";
        }
        else
        {
            cout << (v1[i] - v[n - 1]) << " ";
        }
    }
    cout << endl;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}