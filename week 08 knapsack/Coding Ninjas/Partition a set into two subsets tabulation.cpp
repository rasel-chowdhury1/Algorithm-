//Problem link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;


int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
	for(int i = 0; i < n; i++) totSum += arr[i];

	int k = totSum;

	vector<vector<bool>>dp(n, vector<bool>(k + 1, 0));

	for(int i = 0; i < n; i++) dp[i][0] = true;
	if(arr[0] <= k) dp[0][arr[0]] = true;

	for(int i = 1; i < n ; i++) {
		for(int target = 1; target <= k; target++) {
				bool not_take = dp[i - 1][target];
				bool take = false;
				if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
				dp[i][target] = take | not_take;
		}
	}
	
	int minn = 1e9;
	for(int i = 0; i <= totSum / 2; i++)
	{
		if(dp[n - 1][i] == true){
			minn = min(minn, abs((totSum - i) - i));
		}
	}

	return minn;
}

int main() {

}