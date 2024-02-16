/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
vll V;
bool solve(ll x, ll y, ll n)
{
    if (n == 1)
        return true;
    if (min(y, V[n + 1] - y + 1) > V[n + 1] - V[n])
        return false;
    y = min(y, V[n + 1] - y + 1);
    return solve(y, x, n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, n, x1, y1, x2, y2;
    cin >> t;
    V.push_back(1);
    V.push_back(1);
    for (int i = 0; i < 46; i++)
    {
        V.push_back(V[i] + V[i + 1]);
    }

    while (t--)
    {
        cin >> n >> x1 >> y1;
        if (solve(x1, y1, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}