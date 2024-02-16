/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
ll fun(ll a)
{
    vector<ll> dig;
    ll bi = 0;
    while (a > 0)
    {
        dig.push_back(a % 9);
        a /= 9;
    }
    ll sz = dig.size();
    for (ll i = sz - 1; i >= 0; i--)
    {
        bi = bi * 10 + dig[i];
    }
    return bi;
}
void solve()
{
    ll n;
    cin >> n;
    string s = to_string(fun(n));
    replace(s.begin(), s.end(), '8', '9');
    replace(s.begin(), s.end(), '7', '8');
    replace(s.begin(), s.end(), '6', '7');
    replace(s.begin(), s.end(), '5', '6');
    replace(s.begin(), s.end(), '4', '5');
    cout << s << endl;
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