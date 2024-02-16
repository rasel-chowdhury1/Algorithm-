/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5;
vector<int> adj_list[maxN];
int visited[maxN];
stack<int> node_stack;

/*
Time complexity: O(N + E) 
Space complexity: O(N + E) 
*/

void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
    node_stack.push(node);
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

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    while (!node_stack.empty())
    {
        cout << node_stack.top() << " ";
        node_stack.pop();
    }
    cout << "\n";

    return 0;
}