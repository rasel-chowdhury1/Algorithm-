/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vll vector<ll>
#define endl "\n"
using namespace std;

int main()
{
    fast;

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' ||
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        {
            s.erase(i, 0);
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            cout << "." << s[i];
        }
    }

    return 0;
}