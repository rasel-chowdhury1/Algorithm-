#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
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
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5;
// int visited[N];
// vector<int> adj_list[N];
 /*
5 6
0 1
1 2
2 0
3 4
3 2
4 1
 */
// void dfs(int node)
// {
//     visited[node] = 1;
//     for (int adj_node : adj_list[node])
//     {
//         if (visited[adj_node] == 0)
//             dfs(adj_node);
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }
//     int cnt = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i] == 0)
//         {
//             cnt++;
//             dfs(i);
//         }
//     }

//     cout << cnt << "\n";

//     return 0;
// }