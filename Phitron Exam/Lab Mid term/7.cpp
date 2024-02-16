#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n < 9) return n;
    return n % 10 + solve(n / 10);
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}