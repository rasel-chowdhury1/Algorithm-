#include <bits/stdc++.h>
using namespace std;
const int maxN = 100;
vector<int> adj[maxN];
bool visited[maxN];

void bfs(int s)
{
    queue<int> q;
    cout << s << " ";
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto child : adj[parent])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push(child);
                cout << child << " ";
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    
        adj[v].push_back(u);
    }

   
    bfs(2);
}

/*
 10 8
 1 2
 1 3
 2 4
 3 4
 3 6
 4 6
 6 7
 6 8

*/