/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
/*
9 11
3 6
3 2
3 1
3 7
2 0
2 1
6 0
4 0
4 1
6 7
7 8

*/
const int N = 2e5;

vector<int> adj_list[N];
int visited[N];
int level[N];

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    level[node] = 0;
    q.push(node);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(3);

    for (int i = 0; i < n; i++)
    {
        cout << "Node : " << i << " -> level -> " << level[i] << endl;
    }

    return 0;
}