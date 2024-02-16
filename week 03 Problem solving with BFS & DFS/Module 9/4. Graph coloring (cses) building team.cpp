#include <bits/stdc++.h>
using namespace std;

/*
5 4
1 2
1 3
2 3
4 5

Output ->
1 2 2 1 2
1 2 2 2 1
2 1 1 2 1


(2)  (1)
1 -- 2
|
3
(1)

(2)  (1)
4 -- 5
*/

/*
Time complexity: O(N + E) 
Space complexity: O(N + E) 
*/
const int N = 2e5 + 5;

int visited[N];
int color[N];
vector<int> adj_list[N];

bool dfs(int node)
{
    visited[node] = 1;

    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            if (color[node] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;

            bool is_biocolorable = dfs(adj_node);
            if (!is_biocolorable)
                return false;
        }
        else
        {
            if (color[node] == color[adj_node])
            {
                return false;
            }
        }
    }
    return true;
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

    bool is_bicolorable = true;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = dfs(i);

            if (!ok)
            {
                is_bicolorable = false;
                break;
            }
        }
    }

    if (!is_bicolorable)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}