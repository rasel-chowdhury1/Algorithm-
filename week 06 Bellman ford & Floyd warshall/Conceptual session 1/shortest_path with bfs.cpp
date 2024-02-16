#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
vector<int> parent;
vector<bool> visited;

vector<int> find_path(int d)
{
    vector<int> path;
    int x = d;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<int> bfs(int src, int dest)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    vector<int> path = {-1};
    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        if (head == dest)
        {
            path = find_path(dest);
            return path;
        }

        for (auto child : adj_list[head])
        {
            if (visited[child] == false)
            {
                visited[child] = true;
                q.push(child);
                parent[child] = head;
            }
        }
    }
    
    return path;
}

int main()
{

    int n, e;
    cin >> n >> e;

    parent.resize(n, -1);
    visited.resize(n, false);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src, dest;
    cin >> src >> dest;

    vector<int> path = bfs(src, dest);

    for (auto val : path)
        cout << val << ' ';
    cout << endl;

    return 0;
}

/*

5 6

1 2
1 3
2 3
4 0
3 0
4 2

0 1

*/