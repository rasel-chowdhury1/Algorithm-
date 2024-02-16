#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 2e5;
vector<int> adj_list[N];
int visited[N], parent[N];
int start, endd;

bool detect_cycle(int src)
{
    visited[src] = 1;

    for (auto adj_node : adj_list[src])
    {
        if (adj_node == parent[src])
            continue;
        if (visited[adj_node] == 0)
        {
            parent[adj_node] = src;
            bool ok = detect_cycle(adj_node);
            if (ok)
                return true;
        }
        if (visited[adj_node] == 1)
        {
            start = src;
            endd = adj_node;
            return true;
        }
    }
    visited[src] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bool ok = detect_cycle(i);
            if (ok)
            {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)cout<<"Cycle Exist"<<endl;
    else cout<<"No Cycle"<<endl;

    return 0;
}