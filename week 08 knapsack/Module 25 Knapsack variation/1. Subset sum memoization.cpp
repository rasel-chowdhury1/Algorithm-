#include <bits/stdc++.h>
using namespace std;

/*
- state: subset_sum(n, target) -> returns 1 if it is possible to create a subset from numbers
         1 to n and from the sum "target"

- recurrance: subset_sum(n, target) -> subset_sum(n - 1, target) OR 
                                subset_sum(n - 1, target - nums[n]) if target >= nums[n]

- base case: subset_sum(0, target) -> 1, if target == 0
                            else 0.

test case:
>>
3 9
4 2 5

>>
1 3
4
*/

const int N = 101;
const int M = 1e5 + 5;
int dp[N][M];
int nums[N];

int subset_sum(int n, int target){
    //base_case:
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }

    //if answer is already calculated then return it
    if(dp[n][target] != -1) return dp[n][target];

    // calculate result from smaller sub-problem.
    int ans1 = subset_sum(n - 1, target);
    if(target < nums[n]) return dp[n][target] = ans1;
    
    int ans2 = subset_sum(n - 1, target - nums[n]);

    return dp[n][target] = ans1 or ans2;

}

int main(){
    int n, target;
    cin >> n >> target;

    for(int i = 1; i <= n; i++) cin >> nums[i];

    memset(dp, -1, sizeof(dp));

    cout << subset_sum(n, target) << endl;

    return 0;
}