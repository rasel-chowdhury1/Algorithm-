// Problem link: https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

/*
1. state: f(m, n) -> number of minimum cost to reach from (0, 0) to (m, n).
2. recurrance: f(m, n) -> min( grid[m][n] + f(m - 1, n) , grid[m][n] + f(m, n - 1))
3. base case: f(0 , 0) = grid[m][n]

*/

int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0) return grid[m][n];
    if (m < 0 || n < 0) return 1e9;

    if (dp[m][n] != -1) return dp[m][n];

    return dp[m][n] = min(grid[m][n] + f(m - 1, n, grid, dp) , grid[m][n] + f(m, n - 1, grid, dp));   
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m , vector<int>(n, -1));

    return f(m - 1, n - 1, grid, dp);
}

int main()
{
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}};
    cout << minPathSum(grid) << endl;
}
