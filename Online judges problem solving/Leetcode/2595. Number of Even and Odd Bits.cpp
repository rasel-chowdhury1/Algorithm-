/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        int odd = 0, even = 0;
        int x = 1;
        while (n)
        {
            int bit = n & 1;
            n = n >> 1;
            x++;
            if(bit==1)
            {
                if(x%2)odd++;
                else even++;
            }
        }
        return {even, odd};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    int n;
    cin >> n;

    vector<int> ans = s.evenOddBit(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}