/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
    //Problem lin: https://leetcode.com/problems/longest-palindromic-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Memoization:
    int LCS(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + LCS(i - 1, j - 1, s, t, dp);
        return dp[i][j] = max(LCS(i - 1, j, s, t, dp), LCS(i, j - 1, s, t, dp));
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();

        vector<vector<int>>dp(n + 5, vector<int>(n + 5, -1));
        return LCS(n - 1, n - 1, s, t, dp);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}