#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 20010;
vector<int> adj_list[N];
int mark[N];
int color[N];

enum
{
    NOT_VISITED,
    BLACK,
    RED
};

int bfs(int src)
{
    queue<int> q;
    ll black = 0, red = 0;
    q.push(src);
    color[src] = BLACK;
    black++;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj_list[u].size(); i++)
        {
            int v = adj_list[u][i];
            if (color[v] == NOT_VISITED)
            {
                q.push(v);
                if (color[u] == BLACK)
                {
                    color[v] = RED;
                    red++;
                }
                else
                {
                    color[v] = BLACK;
                    black++;
                }
            }
        }
    }
    return max(black, red);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < N; i++)
            adj_list[i].clear();
        for (int j = 0; j < n; j++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        ll sum = 0;
        memset(color, 0, sizeof(color));

        for (int j = 0; j < 20005; j++)
        {
            if (color[j] == 0 and !adj_list[j].empty())
                sum += bfs(j);
        }
        cout << "Case " << i << ": " << sum << "\n";
    }
    return 0;
}