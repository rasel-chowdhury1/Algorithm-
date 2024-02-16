// // Problem link: https://codeforces.com/contest/1829/problem/E

#include <bits/stdc++.h>
using namespace std;


const int maxN = 1005;

int visited[maxN][maxN];
vector<int> arr[maxN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(int x, int y, int n, int m)
{
    if (x >= 0 and y >= 0 and x < n and y < m and !visited[x][y] and arr[x][y] != 0)
    {
        return true;
    }
    return false;
}

int dfs(int x, int y, int n, int m)
{
    int result = arr[x][y];
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (isSafe(n_x, n_y, n, m))
        {
            visited[n_x][n_y] = true;
            result += dfs(n_x, n_y, n, m);
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            arr[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                visited[i][j] = false;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] or arr[i][j] == 0)
                    continue;
                ans = max(ans, dfs(i, j, n, m));
            }
        }

        cout << ans << "\n";
    }

    return 0;
}