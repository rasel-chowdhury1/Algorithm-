/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5;
vector<int> adj_list[maxN];
int visited[maxN];
/*
test case:
4 4
1 3
2 1
2 4
3 4
output -> No cycle

>>
4 5
1 3
2 1
2 4
3 2
3 4
output -> cycle exist
*/

/*
Time complexity: O(N + E)
Space complexity: O(N + E)
*/

bool dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            bool got_cycle = dfs(adj_node);
            if (got_cycle)
                return true;
        }
        else if (visited[adj_node] == 1)
            return true;
    }
    visited[node] = 2;
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
    }

    bool ans = false;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bool got_cycle = dfs(i);
            if (got_cycle)
            {
                ans = true;
                break;
            }
        }
    }

    if (ans)
        cout << "Cycle Exist\n";
    else
        cout << "No cycle\n";

    return 0;
}