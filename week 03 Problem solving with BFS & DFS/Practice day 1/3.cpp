/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

/*
test case:
5 8
########
#..#...#
####.#.#
#..#...#
########

>>

10 10
#11#2##33#
#1#####3#4
####5####4
666#5#7###
#######888
#99#b###c#
a#9#b#####
###d#e#fff
#gg###h##i
###...##.#



>>

10 10
####.###..
#.######.#
##.######.
###.###..#
##.####..#
#####..###
#.########
#.####.#.#
#####..##.
######.###

*/
const int N = 2005;
int visited[N][N], maze[N][N];

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
    if (maze[i][j] == -1)
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid(new_x, new_y) && is_safe(new_x, new_y) && visited[new_x][new_y] == 0)
        {
            visited[new_x][new_y] = 1;
            dfs(new_x, new_y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            if (str[j] == '#')
            {
                maze[i][j] = -1;
            }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << maze[i][j] << "\t";
    //     cout << endl;
    // }

    int room_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                dfs(i, j);
                room_cnt++;
            }
        }
    }

    cout << room_cnt << endl;

    return 0;
}