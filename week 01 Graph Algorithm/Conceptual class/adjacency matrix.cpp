#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int adj_matrix[nodes + 1][nodes + 1];

    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
