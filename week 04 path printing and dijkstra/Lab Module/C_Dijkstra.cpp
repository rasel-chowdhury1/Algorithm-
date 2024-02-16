#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(m logn)
Space Complexity: O(m)

problem link: https://codeforces.com/problemset/problem/20/C
*/

const int N = 1e5;
const long long infinity = 1e18;

vector<pair<int, int>> adj_list[N];
int nodes, edges;
int visited[N], parent[N];
long long Distance[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        Distance[i] = infinity;
    }

    Distance[src] = 0;

    priority_queue<pair<long long, int>> pq;

    pq.push({0, src});
    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();
        
        int selected_node = head.second;

        if (visited[selected_node])
            continue;

        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if (Distance[selected_node] + edge_cost < Distance[adj_node])
            {
                Distance[adj_node] = Distance[selected_node] + edge_cost;
                parent[adj_node] = selected_node;
                pq.push({-Distance[adj_node], adj_node});
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

    int current_node = nodes;

    vector<int> path;

    while (true)
    {
        path.push_back(current_node);
        if (current_node == src)
            break;
        current_node = parent[current_node];
    }

    reverse(path.begin(), path.end());

    for (auto val : path)
        cout << val << " ";
    cout << endl;

    return 0;
}