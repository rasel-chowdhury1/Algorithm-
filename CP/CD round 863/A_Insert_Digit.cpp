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
    ll n, d;
    cin >> n >> d;

    string str;
    cin >> str;
    string s = to_string(d);
    if (d == 0)
    {
        str += s[0];
        cout << str << endl;
        return;
    }
    for (ll i = 0; i < n; i++)
    {
        if (str[i] < s[0])
        {
            str.insert(i, s);
            cout << str << endl;
            return;
        }
    }
    str += s[0];
    cout << str << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}