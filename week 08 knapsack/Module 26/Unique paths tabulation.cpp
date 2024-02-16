// Problem link: https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;

/*
1. state: uniquePaths(m, n) -> number of unique paths from (0, 0) to (m, n).
2. recurrance: uniquePaths(m, n) -> uniquePaths(m - 1, n) + uniquePaths(m, n - 1)
3. base case: uniquePaths(0 , 0) = 1
*/

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>>dp(m, vector<int>(n, -1));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0 and j == 0) continue;

            int ans = 0;
            if(i > 0) ans += dp[i - 1][j] ;
            if(j > 0) ans += dp[i][j - 1] ;

            dp[i][j] = ans;
        }
            
    }

    cout << dp[m - 1][n - 1] << endl;
    return 0;
    
}