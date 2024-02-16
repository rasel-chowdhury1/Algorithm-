#include <bits/stdc++.h>
using namespace std;
vector<int>dp(31,0);
class Solution {
public:
    // int dp[31];
    int fib(int n) {
        if(n == 0)return 0;
        if(n <= 2) return 1;

        if(dp[n] != 0) return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.fib(n) << endl;
    return 0;
}