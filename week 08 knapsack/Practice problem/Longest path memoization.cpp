// Problem link: https://atcoder.jp/contests/dp/tasks/dp_g
/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> dp(N, -1);
vector<int> edge_list[N];
vector<int> visited(N);

void long_path(int node)
{
    visited[node] = 1;
    dp[node] = 0;

    for (int parent : edge_list[node])
    {
        if (visited[parent] == 0)
        {
            long_path(parent);
        }
        dp[node] = max(dp[node], 1 + dp[parent]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge_list[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            long_path(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}
