#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        if (i % 2 != 0)
            swap(s[i - 1], s[i]);
    }
    cout << s;
}