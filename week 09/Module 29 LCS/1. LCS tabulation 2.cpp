#include <bits/stdc++.h>
using namespace std;

string s, t;
const int N = 3003;
int dp[N][N];

int main() {

    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    
    //Base case:
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    //loop over the states
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[i - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    
    return 0;
}