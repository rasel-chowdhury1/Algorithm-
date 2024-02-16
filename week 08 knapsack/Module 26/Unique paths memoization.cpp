// Problem link: https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;

/*
1. state: uniquePaths(m, n) -> number of unique paths from (0, 0) to (m, n).
2. recurrance: uniquePaths(m, n) -> uniquePaths(m - 1, n) + uniquePaths(m, n - 1)
3. base case: uniquePaths(0 , 0) = 1
*/

int fun(int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 or m < 0) return 0;
    if (n == 0 && n == 0) return 1;

    if (dp[n][m] != -1)  return dp[n][m];

    return dp[n][m] = fun(n - 1, m, dp) + fun(n, m - 1, dp);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun(m - 1, n - 1, dp);
}

int main()
{
    int row, col;
    cin >> row >> col;

    cout << uniquePaths(row, col) << endl;
}
