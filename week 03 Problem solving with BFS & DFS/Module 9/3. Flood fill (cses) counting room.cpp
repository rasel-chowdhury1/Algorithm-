/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

output -> 3

while there exists an empty cell
    - find an empty unvisited cell
    - run bfs() from that cell




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
ll maze[N][N], visited[N][N];
ll n, m;
ll dx[] = {0, 0, -1, 1};
ll dy[] = {1, -1, 0, 0};

bool is_inside(pair<ll, ll> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;
    if (x >= 0 && x < n && y >= 0 && y < m)
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
/*
Time complexity: O(N * M) 
Space complexity: O(N * M) 
*/

void bfs(pair<ll, ll> src)
{
    queue<pair<ll, ll>> q;
    visited[src.first][src.second] = 1;

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
                q.push(adj_node);
            }
        }
    }
}

pair<ll, ll> find_unvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    fast;
    cin >> n >> m;

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
        }
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    int room_cnt = 0;

    while (true)
    {
        pair<ll, ll> unvisited_pos = find_unvisited();
        if (unvisited_pos == pair<ll, ll>{-1, -1})
        {
            break;
        }
        bfs(unvisited_pos);
        room_cnt++;
    }

    cout << room_cnt << endl;

    return 0;
}