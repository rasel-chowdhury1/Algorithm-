#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;
vector<pair<int, int>> adj_list[N];
int d[N];

/*
Input ->
4 3
1 2 5
2 3 -2
3 4 6

output -> 0 5 3 9
*/

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i <= n; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int source = 1;
    d[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int node = 1; node <= e; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v]) d[v] = d[u] + w;
                
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }

    cout<<endl;
    
}