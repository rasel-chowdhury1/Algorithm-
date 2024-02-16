#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int M = 101;
int dp[N][M];

int maxSum(vector<int> &wt, vector<int> &val, int size, int weight)
{
    if(size == 0 or weight == 0) return 0;

    if(dp[size][weight] != -1) return dp[size][weight];

    if(wt[size - 1] <= weight) {
        return dp[size][weight] = max(val[size - 1] + maxSum(wt, val, size - 1, weight - wt[size - 1]), maxSum(wt, val, size - 1, weight));
    }
    else {
        return dp[size][weight] = maxSum(wt, val, size - 1, weight);
    }

}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> wt, val;

    for (int i = 1; i <= n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        
        wt.push_back(weight);
        val.push_back(value);
    }

    memset(dp, -1, sizeof(dp));

    cout << maxSum(wt, val, n, target);
    return 0;
}