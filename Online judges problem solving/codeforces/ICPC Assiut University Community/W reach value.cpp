#include <bits/stdc++.h>
using namespace std;

bool reachValue(long long cur, long long target) {
    if(cur == target) return true;

    if(cur > target) return false;

    return reachValue(cur * 10, target) or reachValue(cur * 20 , target);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        if(reachValue(1, n) == true) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}