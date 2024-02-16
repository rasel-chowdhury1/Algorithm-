/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69

Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9


Approach for grid:
(x,y) -> right -> (x, y+1)
    -> left -> (x, y-1)
    -> top -> (x - 1, y)
    -> bottom -> (x + 1, y)

generalize formula:
ll dx[] = {0, 0, -1, 1};
ll dy[] = {1, -1, 0, 0};

 for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dx[i];
    }


1. is the cell with in the maze;
2. is the cell forbidden/wall? --- or is the cell is safe?
3. is the cell visited?


Time complexity: O(n*m) at worst case
Space complexity: O(n*m) at worst case
*/ 
#include <bits/stdc++.h>
#define ll long long int
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vll vector<ll>
#define endl "\n"
using namespace std;

const ll N = 2002;
ll maze[N][N];
ll level[N][N], visited[N][N];
ll n, m;
ll dx[] = {0, 0, -1, 1};
ll dy[] = {1, -1, 0, 0};

bool is_inside(pair<ll, ll> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (x > 0 && x < n && y > 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<ll, ll> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (maze[x][y] == -1)
    {
        return false;
    }
    return true;
}

void bfs(pair<ll, ll> src)
{
    queue<pair<ll, ll>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty())
    {
        pair<ll, ll> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<ll, ll> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    fast;
    cin >> n >> m;
    pair<ll, ll> src, des;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j] = -1;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if (s[j] == 'A')
            {
                src = {i, j};
            }
            else if (s[j] == 'B')
            {
                des = {i, j};
            }
        }
    }

    bfs(src);

    if (level[des.first][des.second] == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << level[des.first][des.second] << endl;
    }



    return 0;
}