#include <bits/stdc++.h>
using namespace std;

/*
test case:
5 8
########
#.A#...#
#.##.#B#
#......#
########

-----------------------for 8 moves.
dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}
dy[8] = {0, 0, -1, 1, -1, 1, -1, 1}
dir[8] = D  U   L  R  UL  UR  DL DR
*/



const int maxN = 1010;
bool visited[maxN][maxN];
char grid[maxN][maxN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};
pair<int, int> parent[maxN][maxN];

void bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    parent[x][y] = {-1, -1};

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx_ = u.first + dx[i];
            int dy_ = u.second + dy[i];
            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] != '#')
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
                parent[dx_][dy_] = u;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start_x, start_y, end_x, end_y;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs(start_x, start_y, n, m);

    if (visited[end_x][end_y])
    {
        cout << "YES\n";
        vector<pair<int, int>> path;
        path.push_back({end_x, end_y});

        int x = end_x, y = end_y;
        while (parent[x][y] != make_pair(-1, -1))
        {
            pair<int, int> p = parent[x][y];
            x = p.first, y = p.second;
            path.push_back({x, y});
        }
        reverse(path.begin(), path.end());
        string ans;

        for (int i = 0; i < path.size() - 1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int dx_, dy_;
                dx_ = path[i].first + dx[j];
                dy_ = path[i].second + dy[j];

                if (dx_ == path[i + 1].first && dy_ == path[i + 1].second)
                {
                    ans.push_back(dir[j]);
                    break;
                }
            }
        }

        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}