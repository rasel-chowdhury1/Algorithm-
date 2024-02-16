/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
    Problem link: https://leetcode.com/problems/delete-operation-for-two-strings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int LCS(int i, int j, string s, string t, vector<vector<int>>&dp){

        if(i == 0 or j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == t[j - 1]) return dp[i][j] = 1 + LCS(i - 1, j - 1, s, t, dp);
        else return dp[i][j] = max(LCS(i - 1, j, s, t, dp), LCS(i, j - 1, s, t, dp));
    }

    int minDistance(string word1, string word2) {
        int n, m;
        n = word1.size();
        m = word2.size();
        vector<vector<int>>dp(n + 5, vector<int>(m + 5, -1));

        // string size - 2 * maximum size of subsequence (LCM)
        return n + m - (2 *LCS(n, m, word1, word2, dp));
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}