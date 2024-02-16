// Leetcode problem: 416. Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int>&arr, int n, int sum, vector<vector<int>> &dp)
    {
        if(n == 0) {
            if(sum == 0) return true;
            return false;
        }

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        if (arr[n - 1] > sum) return isSubsetSum(arr, n - 1, sum, dp);

        return dp[n][sum] = isSubsetSum(arr, n - 1, sum, dp) || isSubsetSum(arr, n - 1, sum - arr[n - 1], dp);
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2)
            return false;

        vector<vector<int> > dp(n + 1, vector<int>(sum + 1, -1));

        return isSubsetSum(nums, n, sum / 2, dp);
    }
};

int main()
{
}
