#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        int c = max(a, b);
        if (a == b)
        {
            cout << c * 2 << '\n';
        }
        else
        {
            cout << c * 2 - 1 << '\n';
        }
    }
}