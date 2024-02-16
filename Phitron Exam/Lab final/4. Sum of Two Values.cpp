// Problem link: https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int arr[n + 1];
    vector<pair<int, int>> pr;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pr.push_back(make_pair(arr[i], i + 1));
    }

    sort(pr.begin(), pr.end());

    int i = 0, j = n - 1;

    while (i < j)
    {
        if (pr[i].first + pr[j].first > x)
            j--;
        else if (pr[i].first + pr[j].first < x)
            i++;
        else if (pr[i].first + pr[j].first == x)
        {
            cout << pr[i].second << " " << pr[j].second << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}