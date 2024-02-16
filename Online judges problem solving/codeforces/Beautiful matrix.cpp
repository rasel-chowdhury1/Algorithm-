#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 1) cout << abs(i - 2) + abs(j - 2);
        }
    }
}