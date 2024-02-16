/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
ll solve(ll a)
{
    ll x = sqrt(a) + 2;
    while (x * x > a) x--;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin >> t;
    while (t--)
    {
        ll n;cin >> n;
        cout << solve(n - 1) << endl;
    }

    return 0;
}