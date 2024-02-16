#include <bits/stdc++.h>
using namespace std;

int n, m, rooms;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> vis;

bool isvalid(int x, int y)
{
    if (x < 0 or x >= n or y < 0 or y >= 0)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void dfs(int i, int j)
{
    vis[i][j] = true;
    for (auto child : moves)
    {
        if (isvalid(i + child.first, j + child.second))
        {
            dfs(i + child.first, j + child.second);
        }
    }
}

void connected()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                ++rooms;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vis.resize(n);

    for (int i = 0; i < n; i++)
    {
        vis[i].resize(m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
                vis[i][j] = true;
        }
    }

    connected();
    cout << rooms << "\n";
    return 0;
}