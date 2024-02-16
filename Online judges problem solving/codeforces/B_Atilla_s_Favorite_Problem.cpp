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
    ll t;
    cin>> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char>s(n);
        map<char,int>mp;
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
            if(s[i]>='a' && s[i]<='z'){
                mp[s[i]] = s[i] - 96;
            }
        }
        auto maxx = max_element(mp.begin(),mp.end());
        cout << maxx->second<<endl;       
    }
    return 0;
}