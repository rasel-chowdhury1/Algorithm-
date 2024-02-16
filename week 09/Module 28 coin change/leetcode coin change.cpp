// Problem link: https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> & coin, vector<vector<int>> &dp, int n, int K)
    {
        if(n == 0) {
            if(K % coin[0] == 0) return K / coin[0];
            return 1e9;
        }

        if(dp[n][K] != -1) return dp[n][K];

        int ans1, ans2 = 1e9;
        ans1 = 0 + solve(coin, dp, n - 1, K);

        if(coin[n] <= K) {
            ans2 = 1 + solve(coin, dp, n, K - coin[n]);
        }

        return dp[n][K] = min(ans1, ans2);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n + 5, vector<int>(amount + 5, -1));
        int ans = solve(coins , dp, n - 1, amount);

        if(ans != 1e9) return ans;
        else return -1;
    }
};