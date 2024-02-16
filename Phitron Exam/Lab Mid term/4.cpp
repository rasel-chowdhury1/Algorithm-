#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n^2)
Space Complexity: O(n)

input->
10 10
1 4 201
2 3 238
3 4 40
3 6 231
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

output ->
1 4 6 10



*/

const int N = 1e5;
const int infinity = 1e9;

vector<pair<int, int>> adj_list[N];
int nodes, edges;
int visited[N], Distance[N];
int level[N];
int parent[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        Distance[i] = infinity;
    }

    Distance[src] = 0;
    parent[src] = -1;

    for (int i = 0; i < nodes; i++)
    {
        int selected_node = -1;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            if (selected_node == -1 || Distance[selected_node] > Distance[j])
                selected_node = j;
        }

        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if (Distance[selected_node] + edge_cost < Distance[adj_node])
            {
                Distance[adj_node] = Distance[selected_node] + edge_cost;
                parent[adj_node] = selected_node;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    int dest_node = nodes;

    if (visited[dest_node] == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int sel_node = dest_node;

    vector<int> path;

    while (true)
    {
        path.push_back(sel_node);
        if (sel_node == src)
            break;
        sel_node = parent[sel_node];
    }
    reverse(path.begin(), path.end());

    for (auto val : path)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}