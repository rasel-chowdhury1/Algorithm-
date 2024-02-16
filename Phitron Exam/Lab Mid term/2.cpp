#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>> adj_list[maxN];
long long d[maxN];
int parent[maxN];

/*
>>input
4 5
1 2 2
2 3 2
1 4 1
3 1 -7
3 4 -2

>>output
YES
1 2 3 1 


*/

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    bool have_cycle = false;
    int last_updated_node = -1;

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
                    parent[v] = u;
                    if (i == n)
                    {
                        have_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if (have_cycle == true)
    {
        cout << "YES" << endl;
        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;

        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == first_node)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        for (auto val : cycle)
            cout << val << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}