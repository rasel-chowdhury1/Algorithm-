#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool visited[1001][1001];
int n;

bool isSafe(int x, int y, int ax, int ay)
{
    if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y]) return false;
    if ((x == ax) || (y == ay)) return false;
    if (x + y == ax + ay)  return false;
    if ((x - ax) == (y - ay)) return false;
    return true;
}

void dfs(int x, int y, int ax, int ay)
{
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        if (isSafe(x + dx[i], y + dy[i], ax, ay))
        {
            dfs(x + dx[i], y + dy[i], ax, ay);
        }
    }
}

int main()
{
    cin >> n;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    ax--; ay--;  
    bx--;  by--; 
    cx--;  cy--;

    dfs(bx, by, ax, ay);
    
    if (visited[cx][cy]) cout << "YES";
    else  cout << "NO";
    
    return 0;
}
