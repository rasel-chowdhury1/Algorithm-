#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adjList[n + 1];
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adjList[i])
            cout << j << " ";
        cout << "\n";
    }
}