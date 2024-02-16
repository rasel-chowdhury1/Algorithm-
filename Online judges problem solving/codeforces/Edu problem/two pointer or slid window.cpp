/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = 0, sum = 0, ans = -1;
    while (r < n)
    {
        sum += v[r];
        if (r - l + 1 < k)
            r++;
        else if (r - l + 1 == k)
        {
            // cout<<sum<<" ";
            ans = max(ans, sum);
            sum -= v[l];
            l++;
            r++;
        }
    }
    cout << sum << endl;

    return 0;
}

/*
9 3
5 6 1 13 7 5 12 8 2
*/