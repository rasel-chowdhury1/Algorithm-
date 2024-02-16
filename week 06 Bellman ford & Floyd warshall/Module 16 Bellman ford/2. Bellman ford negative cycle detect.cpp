#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;
vector<pair<int, int>> adj_list[N];
int d[N];

/*
Input ->
4 4
1 2 5
2 3 -2
3 4 6
3 1 -7

output -> Graph has negative cycle
*/

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    int src = 1;
    d[src] = 0;

    bool negative_cycle = false;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    if (i == n)
                    {
                        negative_cycle = true;
                    }
                }
            }
        }
    }

    if (negative_cycle)
    {
        cout << "Graph has negative cycle\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << d[i] << " ";
        }
    }

    cout << endl;
    return 0;
}