#include <bits/stdc++.h>
using namespace std;

void getCapital(string str)
{
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        cout << str[0];
        return;
    }
    getCapital(str.substr(1));
}

int main()
{
    string str;
    cin >> str;

    getCapital(str);
    return 0;
}