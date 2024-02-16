/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;
void solve()
{
    string s; cin >> s;
    set<char> sc;
    map<char, int> freq;
    for (auto c : s)
    {
        sc.insert(c);
        freq[c]++;
    }
    if(sc.size()==1)cout<<-1<<endl;
    else if(sc.size()==2){
        int ans = 4;
        for(auto ox:freq)
        {
            if(ox.second==1){
                ans = 6;
                break;
            }
        }
        cout<<ans<<endl;
    }
    else if(sc.size()==3)cout<<4<<endl;
    else if(sc.size()==4)cout<<4<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}