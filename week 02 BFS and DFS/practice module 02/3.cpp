#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;
vector<int> adj_matrix[maxN];
bool visited[maxN] = {false};

int checked = 0;
map<int, int> mp;
void bfs(int node)
{
    queue<int> q;
    visited[node] = true;
    q.push(node);
    
    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (auto child : adj_matrix[head])
        {
            checked++;
            mp[child]++;
            if (!visited[child])
            {
                visited[child] = true;
                q.push(child);
            }
        }
    }
}
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

    bfs(0);
    for (auto it : mp)
    {
        cout << it.first << " -> " << it.second << "\n";
    }

    cout << checked << "\n";
}