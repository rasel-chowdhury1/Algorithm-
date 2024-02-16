#include <bits/stdc++.h>
using namespace std;

const int N = 101;
long long dp[N];
/*
time: O(n)
space: O(n)
*/

long long tribo(int n){
    if(n <= 3) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
    dp[n] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << tribo(n) << endl;
    return 0;

}