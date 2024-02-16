#include <bits/stdc++.h>
using namespace std;
/*
- dp state : steps of climbing top of the stairs 
- recurrence relation : climbStairs(n - 1) + climbStairs(n - 2)
- base case : if stairs less than 1 then return 1

time: O(n)
space: O(n)
*/
vector<int>dp(50, -1);
class Solution
{
public:
    
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans1 = climbStairs(n - 1);
        int ans2 = climbStairs(n - 2);

        int ans = ans1 + ans2;
        dp[n] = ans;
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;

    cout << s.climbStairs(n);
    return 0;
}