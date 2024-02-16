#include <bits/stdc++.h>
using namespace std;
const int maxN = 100;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adjWegList[maxN];
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjWegList[u].push_back({v, w});
        adjWegList[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adjWegList[i])
        {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << "\n";
    }

    return 0;
}
