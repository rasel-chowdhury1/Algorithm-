// /*
//     ** Sujan Sarkar **
//     Github: https://github.com/sujansarkar69
// */
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         long long l, r;
//         cin >> l >> r;
//         long long ans = 0;
//         if (l <= r)
//         {
//             while (l <= r)
//             {
//                 ans += l;
//                 l++;
//             }
//         }
//         else
//         {
//             while (l >= r)
//             {
//                 ans += l;
//                 l--;
//             }
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;

        if (r < l)
        {
            long long temp = l;
            l = r;
            r = temp;
        }

        long long sum = (r * (r + 1)) / 2 - ((l - 1) * l) / 2;

        cout << sum << endl;
    }

    return 0;
}
