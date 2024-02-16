#include <bits/stdc++.h>
using namespace std;

// fibonacci series: 0 1 1 2 3 5 8 13 
int fibo(int n)
{
    if (n == 0)return 0;
    if (n == 1)return 1;
    return (n - 1) + (n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}