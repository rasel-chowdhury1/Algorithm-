#include <bits/stdc++.h>
using namespace std;
int main()
{
/*
adjacency matrix:

    1----2
        / \
       3---4

4 4
1 2
2 3
3 4
2 4

Time Complexity: O(n^2)
Space Complexity: O(n^2)

*/
    int n, e;
    cin >> n >> e;
    int adjMatrix[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    vector<int> vec[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMatrix[i][j] > 0)
                vec[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : vec[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
