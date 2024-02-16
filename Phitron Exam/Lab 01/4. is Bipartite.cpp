#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
vector<int> adj_list[maxN];
int visited[maxN];
int color[maxN];

bool dfs(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            if (color[node] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;

            bool is_bipartite = dfs(adj_node);
            if (!is_bipartite)
                return false;
        }
        else
        {
            if (color[node] == color[adj_node])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bipartite = true;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = dfs(i);
            if (!ok)
            {
                is_bipartite = false;
                break;
            }
        }
    }

    if(is_bipartite)cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}