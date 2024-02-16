#include <bits/stdc++.h>
using namespace std;

/*
Graph:
=====

0 --- 1 ----- 2 --- 3
      |       |
      |       |
      5 ----- 4

output -> 0 1 2 3 4 5

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

6 9
1 2
1 4
2 3
2 5
3 5
3 4
4 5
4 6
5 6

*/

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

void dfs(int node)
{
    cout << node << " ";
    visited[node] = 1;

    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
            dfs(adj_node);
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 2;
    // cin >> src;
    dfs(src);

    return 0;
}