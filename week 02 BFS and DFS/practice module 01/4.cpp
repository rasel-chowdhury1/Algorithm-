#include <bits/stdc++.h>
using namespace std;

void rev_str(string s)
{
    if (s.size() == 0)
        return;
    rev_str(s.substr(1));
    cout << s[0];
}
int main()
{
    string str;
    cin >> str;

    rev_str(str);
    cout << "\n";
    return 0;
}