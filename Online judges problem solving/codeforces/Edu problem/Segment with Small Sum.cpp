#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long int sum = 0, ans = 0, l = 0, r = 0;

    while (r < n)
    {
        sum += v[r];
        if (sum <= k)
        {
            ans = max(ans, r - l + 1);
            r++;
        }
        else if (sum > k)
        {
            while (sum > k && l <= r)
            {
                sum -= v[l];
                l++;
            }
            r++;
        }
    }
    cout << ans << endl;
}

/*
7 20
2 6 4 3 6 8 9
*/