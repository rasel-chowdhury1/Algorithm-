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

int main()
{
    fast;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll l = (n / 2) + 1;
        ll r = 1;
        if (n < 4)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        }
        while (l <= n)
        {
            cout << l << " ";
            l++;
            cout << r << " ";
            r++;

            if (l == n && n % 2 == 1)
            {
                cout << l << " ";
                break;
            }
        }
        cout << endl;
    }

    return 0;
}