//Problem link: https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& coin, vector<vector<int>> &dp) {
        //Base case:
        if(n == 0) return k % coin[0] == 0;
        
        //if answer is already calculated then return it
        if(dp[n][k] != -1) return dp[n][k];

        //calculate the result from similar subproblems.
        int ans1, ans2 = 0;
        ans1 = solve(n - 1, k, coin, dp);
        if(k >= coin[n]) ans2 =  solve(n, k - coin[n], coin, dp);
        return dp[n][k] = ans1 + ans2;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(5000 + 5, vector<int>(5000 + 10, -1));
        return solve(n - 1, amount, coins, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << s.change(k, arr) << endl;
    return 0;
}
