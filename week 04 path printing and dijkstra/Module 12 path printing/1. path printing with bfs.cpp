#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int level[N];
int parent[N]; 

void bfs(int src)
{
    visited[src] = true;
    level[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if (!visited[adj_node])
            {
                visited[adj_node] = true;
                level[adj_node] = level[head] + 1;
                parent[adj_node] = head;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src_node = 1;
    bfs(src_node);
    int destination_node = n;

    if (visited[destination_node] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout<<level[destination_node]<<"\n";
    int selected_node = destination_node;

    vector<int> path;

    while (true)
    {
        path.push_back(selected_node);
        if (selected_node == src_node)
            break;
        selected_node = parent[selected_node];
    }
    reverse(path.begin(), path.end());

    for (auto val : path)
        cout << val << " ";
    cout << "\n";

    return 0;
}