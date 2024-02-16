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

>> 
4 11
5 5 1 11
*/

const int N = 101;
const int M = 1e5 + 5;
int dp[N][M];
int nums[N];

int main(){
    int n, tg;
    cin >> n >> tg;

    for(int i = 1; i <= n; i++) cin >> nums[i];
    // handle base case
    dp[0][0] = 1;
    for (int i = 1; i <= tg; i++) dp[0][i] = 0;
    
    //Loop over the states
    for (int i = 1; i <= n; i++) {
        for (int target = 1; target <= tg; target++)
        {
            int ans1 = dp[i - 1][target];
            if(target < nums[i]) {
                dp[i][target] = ans1;
            }
            else {
                int ans2 = dp[i - 1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }  
    }

    cout << dp[n][tg] << endl;
    return 0;
}