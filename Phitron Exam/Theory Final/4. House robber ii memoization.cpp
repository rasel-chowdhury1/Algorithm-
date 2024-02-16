// problem link: https://leetcode.com/problems/house-robber-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101];

    int robHelper(int n, vector<int> &arr)
    {
        //Base case:
        if(n <= 1) {
            if(n == 0) return arr[0];
            if(n == 1) return max(arr[0], arr[1]);
        }
        //if answer is already calculate then return it
        if (dp[n] != -1)   return dp[n];

        //calculate answer from smaller sub-problems
        int ans = max(robHelper(n - 2, arr) + arr[n], robHelper(n - 1, arr));
        return dp[n] = ans;
    }

    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        if (n == 1)  return nums[0];

        int ans1 = robHelper(n - 2, nums);
        nums.erase(nums.begin());

        memset(dp, -1, sizeof(dp));
        int ans2 = robHelper(n - 2, nums);
        return max(ans1, ans2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}