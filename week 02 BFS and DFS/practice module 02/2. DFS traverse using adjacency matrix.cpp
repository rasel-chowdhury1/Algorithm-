#include <bits/stdc++.h>
using namespace std;

/*
test case:
6 8

0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5

time complexity: O(v^2)
space complexity: O(v+e)
*/
const int maxN = 100;
bool visited[maxN];
int adj_m[maxN][maxN];

void DFS(int node, int n)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_m[node][i] == 1 && !visited[i])
            DFS(i, n);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_m[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_m[u][v] = 1;
        adj_m[v][u] = 1;
    }

    DFS(0, n);

    return 0;
}