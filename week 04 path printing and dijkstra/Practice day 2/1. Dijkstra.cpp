/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 1e5;
vector<pair<int, int>> adj_list[N];
int nodes, edge;
int visited[N], d[N];
const int INF = INT_MAX;

void dijkstra(int src)
{
    for (int i = 0; i < nodes; i++)
        d[i] = INF;
}

int main()
{
    cin >> nodes >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    return 0;
}