#include <bits/stdc++.h>
using namespace std;
int pow_of_n(int n, int m)
{
    if (m == 0)return 1;
    else return n * pow_of_n(n, m - 1);
}
int main()
{
    int n,m;cin>>n>>m;
    cout<<pow_of_n(n,m)<<"\n";
    return 0;
}