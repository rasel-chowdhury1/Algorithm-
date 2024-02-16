/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69


test case:
6 5
1 2
1 4
2 3
4 5
5 6

>>
7 6
1 2
1 3
2 4
2 5
3 6
3 7
*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;
vector<int> adj_list[maxN];
bool visited[maxN];
int short_path[maxN];

void dfs(int node, int dis)
{
    visited[node] = true;
    short_path[node] = dis;
    for (auto adj_node : adj_list[node])
    {
        if (!visited[adj_node])
        {
            dfs(adj_node, dis + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "Nodes :" << i << " -> level: " << short_path[i] << "\n";
    }

    return 0;
}