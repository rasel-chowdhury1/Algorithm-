#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d < b)
    {
        cout << -1 << "\n";
        return;
    }

    ll ans1, aa;
    aa = a + d - b;
    if (aa < c)
    {
        cout << -1 << "\n";
        return;
    }
    ans1 = abs(d - b) + abs(aa - c);
    cout << ans1 << "\n";
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