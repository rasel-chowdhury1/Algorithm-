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
        dp[i][m] = 0;
    }
    for(int j = 0; j <= m; j++) {
        dp[n][j] = 0;
    }

    //loop over the states
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(s[i] == t[i]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0] << endl;
    
    return 0;
}