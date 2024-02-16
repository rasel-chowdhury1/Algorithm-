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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    x1--;
    y1--;
    x2--;
    y2--;
    int min_x1 = min(x1, n - x1 - 1);
    int min_y1 = min(y1, n - y1 - 1);
    int min_x2 = min(x2, n - x2 - 1);
    int min_y2 = min(y2, n - y2 - 1);

    int ans_min1 = min(min_x1, min_y1);
    int ans_min2 = min(min_x2, min_y2);

    cout << abs(ans_min1 - ans_min2) << endl;
    
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