//Problem link: https://leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>&dp) {

        //base case: 
        if(n == 0) return 0;

        //if answer is already calculated then return it
        if(dp[n] != -1) return dp[n];

        //calculate the answer from smaller sub-problem
        int ans = 1e5;
        for(int i = 1; i <= sqrt(n); i++)
        {
            int ii = i * i;
            int cur_ans = 1 + solve(n - ii, dp);
            ans = min(ans, cur_ans);
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n + 5, -1);
        return solve(n , dp);
    }
};