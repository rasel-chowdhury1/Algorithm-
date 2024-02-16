/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69

5 5
1 2
1 3
2 3
4 5
3 5
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 100;
int adj_matrix[N][N];
int visited[N], parent[N], Level[N];

void bfs(int src, int n)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    Level[src] = 1;
    parent[src] = -1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (adj_matrix[head][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                Level[i] = Level[head] + 1;
                parent[i] = head;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    bfs(1, n);

    cout << parent[n] << endl;
}