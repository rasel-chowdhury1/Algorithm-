/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // X = (A * B) - (C * D).
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll X = (A * B) - (C * D);
    cout << "Difference = " << X << endl;
    return 0;
}