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
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)
            even+=v[i];
        else
            odd+=v[i];
    }
    if (even > odd)
        cout << "YES\n";
    else
        cout << "NO\n";
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