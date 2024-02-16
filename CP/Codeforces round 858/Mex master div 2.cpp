// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve()
// {
//     ll n;
//     cin >> n;
//     vector<ll> a(n);

//     ll z = 0, nz = 0, pz = 0;
//     map<ll, ll> mp;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         if (a[i] == 0)
//             z++;
//         else
//         {
//             nz++;
//             mp[a[i]]++;
//             if (a[i] != 1)
//                 pz++;
//         }
//     }
//     if (z >= (nz + 2))
//     {
//         if (mp.find(1) == mp.end())
//             cout << 1 << "\n";
//         else if (pz > 0)
//             cout << 1 << "\n";
//         else
//             cout << 2 << "\n";
//     }
//     else
//         cout << 0 << "\n";
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int zero = 0;
        int nonZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
                nonZero++;
            else
                zero++;
        }
        int ans;
        if (zero == 0)
        {
            ans = 0;
        }
        else
        {
            if (nonZero >= zero - 1)
            {
                ans = 0;
            }
            else
            {
                int mx = *max_element(a.begin(), a.end());
                if (mx == 1)
                {
                    ans = 2;
                }
                else
                {
                    ans = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
