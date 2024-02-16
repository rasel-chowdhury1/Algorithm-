#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
vector<int> adj_list[maxN];
int visited[maxN];

bool dfs(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            bool is_cycle = dfs(adj_node);
            if (is_cycle)
                return true;
        }
        else if (visited[adj_node] == 1)
            return true;
    }
    visited[node] = 2;
    return false;
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
    }

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        bool its_cycle = dfs(i);
        if (its_cycle)
        { 
          ans = true;
          break;
        }
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}