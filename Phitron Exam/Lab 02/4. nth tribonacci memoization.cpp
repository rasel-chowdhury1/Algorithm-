#include <bits/stdc++.h>
using namespace std;

vector<int>dp(38, 0);
class Solution {
public:
    // int dp[38];
    int tribonacci(int n) {
    if(n == 0) return 0;
    if(n <= 2) return 1;

    if(dp[n] != 0) return dp[n];

    return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.tribonacci(n) << endl;
    return 0;
}