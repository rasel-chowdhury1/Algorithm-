/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5;
vector<int> adjlist[maxN];
bool visited[maxN];
int parent[maxN];
int level[maxN];
int n, m;

bool bfs()
{
    queue<int> q;
    visited[1] = true;
    level[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        if (head == n)
            return true;
        for (auto adj_node : adjlist[head])
        {
            if (!visited[adj_node])
            {
                level[adj_node] = level[head] + 1;
                visited[adj_node] = true;
                parent[adj_node] = head;
                q.push(adj_node);
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    if (bfs())
    {
        cout << level[n] << endl;
        int path = n;
        vector<int> res;
        while (path != 0)
        {
            res.push_back(path);
            path = parent[path];
        }
        reverse(res.begin(), res.end());
        for (int node : res)
        {
            cout << node << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}