#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n^2)
Space Complexity: O(n)

input->
6 7
3 4 5
2 3 4
1 3 6
6 2 1
6 4 2
3 6 3
5 1 2

source node = 3
output->
6 4 0 5 8 3

7 12
2 1 3
2 3 18
3 1 22
3 7 1
3 4 2
1 4 1
1 8 3
1 6 3
6 8 2
6 7 2
4 8 10
4 7 4



*/

const int N = 1e5;
const int infinity = 1e9;

vector<pair<int, int>> adj_list[N];
int nodes, edges;
int visited[N], Distance[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        Distance[i] = infinity;
    }

    Distance[src] = 0;

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
                Distance[adj_node] = Distance[selected_node] + edge_cost;
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

    int src = 2;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << Distance[i] << " ";
    }
    cout << endl;

    return 0;
}