//problem link - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int x, int y, int n, int m, vector<vector<int>>&matrix, vector<vector<int>>&dp)
    {
        if(dp[x][y] != -1) return dp[x][y];

        vector<vector<int>>dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int ans = 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(matrix[nx][ny] <= matrix[x][y]) continue;

            ans = max(ans, 1 + dfs(nx, ny, n, m, matrix, dp));
        }
        return dp[x][y] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(i, j, n, m, matrix, dp));
            }
        }
        return ans ;
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}