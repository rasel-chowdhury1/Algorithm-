#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

int minOp(int n)
{
    
    if(n==1) return 0;
    if(n==2) return 1;

    if(dp[n] != -1) return dp[n];

    if(n%3 == 0) dp[n] = 1+ minOp(n/3);
    else if(n%3 == 1) dp[n] = 1+ minOp(n-1);
    else if(n%2 == 0) dp[n] = 1+ minOp(n/2);
    else dp[n] = 1+ minOp(n-1);

    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    
    memset(dp, -1, sizeof(dp));

    cout << minOp(n) << endl;
    return 0;
}
