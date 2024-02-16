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
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
    {
        cout << "+\n";
    }
    else if (a - b == c)
    {
        cout << "-\n";
    }
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