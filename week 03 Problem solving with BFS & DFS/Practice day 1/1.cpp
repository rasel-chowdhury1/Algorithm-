/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int visited[N];
void dfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    q.push(node);

    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            visited[adj_node] = 1;
            q.push(adj_node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}


