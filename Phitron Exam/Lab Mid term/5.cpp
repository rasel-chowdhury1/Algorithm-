#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int visited[N][N], room[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;

bool is_valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    return false;
}

bool is_safe(int i, int j)
{
    if (room[i][j] == -1)
    {
        return false;
    }
    return true;
}

/*
5 8
########
#..#...#
#.##.#.#
.#.#...#
#.######

2 8
....#..#
...#..##
*/

int max_len_room = 0;


void dfs(int x, int y, int &len_room)
{
    len_room++;
   
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid(new_x, new_y) && is_safe(new_x, new_y) && visited[new_x][new_y] == 0)
        {
            visited[new_x][new_y] = 1;
            dfs(new_x, new_y, len_room);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '#')
            {
                room[i][j] = -1;
            }
        }
    }

    int room_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && room[i][j] == 0)
            {
                int len_room = 0;
                dfs(i, j, len_room);
                // cout << len_room << endl;
                room_cnt++;
                max_len_room = max(max_len_room, len_room);
            }
        }
    }

    cout << "Rooms - " << room_cnt << endl;
    cout << "Length of the longest room - " << max_len_room << endl;

    return 0;
}