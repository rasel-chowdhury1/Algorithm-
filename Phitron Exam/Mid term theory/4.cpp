#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
int sumArr(int arr[], int sz)
{
    if (sz == 0) return 0;
    if (sz == 1) return arr[1];
    if(sz > 1) return arr[1] + sumArr(arr + 1, sz - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
   
    int ans = sumArr(arr, n);
    cout << ans << endl;

    return 0;
}