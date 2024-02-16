/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69

test case:
5 5
1 2
1 3
2 3
4 5
3 5
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N], parent[N], level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                parent[adj_node] = head;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n, m; // n = node; m = edge;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src_node = 1;
    bfs(src_node);

    int des_node = 4; //des = destination

    cout<<level[des_node]<<endl;
    
    int sel_node = des_node; // sel = selected
    vector<int>path;

    while (true)
    {
        path.push_back(sel_node);
        if(sel_node == src_node)break;
        sel_node = parent[sel_node];
    }

    reverse(path.begin(),path.end());
    for(auto val: path)cout<<val<<" ";
    cout<<endl;
    
    return 0;
}