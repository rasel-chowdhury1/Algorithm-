#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;
vector<int> adj_matrix[maxN];
bool visited[maxN] = {false};

bool bfs(int start, int end)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        if (start == end)
            return true;

        for (auto child : adj_matrix[head])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push(child);
            }
        }
    }
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
        adj_matrix[u].push_back(v);
        adj_matrix[v].push_back(u);
    }
    int start = 2;
    int end = 6;

    if (bfs(start, end))
        cout << "Connected\n";
    else
        cout << "Not connected\n";
    return 0;
}

/*
9 11
0 2
7 8
0 4
0 5
6 7
1 4
1 5
2 3
2 4
4 5
8 6

*/