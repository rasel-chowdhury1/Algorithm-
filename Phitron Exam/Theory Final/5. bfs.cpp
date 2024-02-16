#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool visited[1001][1001];
int n;

bool isSafe(int x, int y, int ax, int ay)
{
    if (x < 1 || x > n || y < 1 | y > n) return true;
    if (x == ax || y == ay || abs(x - ax) == abs(y - ay))  return true;
    if (visited[x][y]) return true;
    return false;
}

void bfs(int ax, int ay, int bx, int by)
{
    queue<pair<int, int>> q;
    q.push({bx, by});
    visited[bx][by] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if(isSafe(x, y, ax, ay)) continue;

            visited[x][y] = true;
            q.push({x, y});
        }
    }
}

int main()
{
    cin >> n;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bfs(ax, ay, bx, by);

    if (visited[cx][cy])  cout << "YES";
    else cout << "NO";

    return 0;
}
