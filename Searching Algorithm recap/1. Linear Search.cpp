#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)

test case:
5 8
2 8 4 8 9
*/

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if(arr[i] == k) {
            // cout << "YES\n";
            // return 0;
            cout << i << " ";
        }
    }
    // cout << "NO\n";
    cout << "\n";
    return 0;
}

