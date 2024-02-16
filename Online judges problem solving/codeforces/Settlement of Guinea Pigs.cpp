#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, c1, c2, ans;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        c1 = c2 = 0;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 2)
            {
                c1 = c1 + c2;
                if (c1 > 0)
                    ans = max(ans, (c1 + 2) / 2);
                c2 = 0;
            }
            else
            {
                c2++;
                if (c1 == 0)
                    ans = max(ans, c2);
                
                else
                    ans = max(ans, (c1 + 2) / 2 + c2);
            }
        }
        cout << ans << "\n";
    }
}