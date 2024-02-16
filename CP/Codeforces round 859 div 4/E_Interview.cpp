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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        int ans;
        int low = 1, high = n;
        while (low<=high)
        {
            int mid = low + (high - low) / 2;
            int len = mid - low + 1;
            if(low==high)
            {
                ans = mid;
                break;
            }
            cout<<"? "<<len<<" ";
            ll sum = 0;
            for (int i = low; i <= mid; i++)
            {
                cout << i <<" ";
                sum +=a[i];
            }
            cout << endl;
            fflush(stdout);
            ll res;
            cin >> res;
            if(res > sum)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        cout<<"! "<<ans<<endl;
        fflush(stdout);
    }
    return 0;
}