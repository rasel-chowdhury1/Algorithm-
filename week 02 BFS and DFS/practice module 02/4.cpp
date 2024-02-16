#include <bits/stdc++.h>
using namespace std;
/*
Graph:
=====

0 --- 1 ----- 2 --- 3
      |       |
      |       |
      5 ----- 4

output -> 0 1 2 5 3 4

No of node -> 6
No of edge -> 6

list of adjacent node->

6 6

0 1
1 2
1 5
2 3
2 4
5 4

*/
const int maxN = 1e5;
vector<int> adj_matrix[maxN];
bool visited[maxN];
map<int, int> mp;
int checked = 0;

void dfs(int node)
{
    visited[node] = true;
    for (auto child : adj_matrix[node])
    {
        mp[child]++;
        checked++;
        if (!visited[child])
            dfs(child);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u].push_back(v);
        adj_matrix[v].push_back(u);
    }

    dfs(0);
    for (auto it : mp)
        cout << it.first << " -> " << it.second << "\n";
    cout << checked << "\n";
}