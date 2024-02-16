#include <bits/stdc++.h>
using namespace std;

const int N = 101;
/*

- fib(n) = calculates the nth fibonacci number
- fib(n) = fib(n - 1) + fib(n - 2)
- fib(1) = 1, fib(2) = 1

*/
long long dp[N]; //dp array

long long fib(int n){
    //1. define base case
    if(n <= 2) return 1;

    //2. check if current state is already solved
    if(dp[n] != -1) return dp[n];
    
    //3. calculate from smaller sub-problems
    long long ans = fib(n - 1) + fib(n - 2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    //mark all state as unvisited
    memset(dp, -1, sizeof(dp));

    cout << fib(n) << endl;
    return 0;
}