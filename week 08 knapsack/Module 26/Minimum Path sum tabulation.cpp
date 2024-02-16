// Problem link: https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

/*
1. state: f(m, n) -> number of minimum cost to reach from (0, 0) to (m, n).
2. recurrance: f(m, n) -> min( grid[m][n] + f(m - 1, n) , grid[m][n] + f(m, n - 1))
3. base case: f(0 , 0) = grid[m][n]

*/

int main()
{
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}};

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m , vector<int>(n, -1));

    dp[0][0] = grid[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
             if(i == 0 && j == 0) continue;
            int ans1, ans2;
            
            if(i > 0) ans1 = grid[i][j] + dp[i - 1][j];
            if(j > 0) ans2 = grid[i][j] + dp[i][j - 1];
            
            int ans = min(ans1, ans2);
            dp[i][j] = ans;
        }
        
    }

    cout << dp[m - 1][n - 1] << endl;
    
}
