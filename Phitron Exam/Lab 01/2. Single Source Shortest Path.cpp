#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
vector<int> adj_list[maxN];
bool visited[maxN];
int level[maxN];

void bfs(int node)
{
    queue<int> q;
    visited[node] = true;
    level[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto adj_node : adj_list[head])
        {
            if (!visited[adj_node])
            {
                visited[adj_node] = true;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(0);
    
    for (int i = 0; i < n; i++)
        cout << "node " << i << "-> level:" << level[i]<<"\n";

    return 0;
}