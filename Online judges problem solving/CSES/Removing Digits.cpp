#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxN = 1e6 + 10;
vector<int>dp(maxN, INT_MAX);
int solve(int i)
{
    if(i == 0) return 0;
    if(dp[i] != INT_MAX) return dp[i];

    vector<int>digit;

    for(auto j: to_string(i))
        digit.push_back(j - '0');
    
    for(auto val: digit) 
        dp[i] = min(dp[i], solve(i - val) + 1);
    
    return dp[i];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n) << endl;
  
    return 0;
}