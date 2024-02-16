#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) {
            for(int k = n; k > i; k--) {
                cout << " ";
            }

            for(int j = 1; j <= 2 * i - 1; j++) {
                cout << "<";
            }cout << "\n";
        }
        else {
            for(int k = n; k > i; k--) {
                cout << " ";
            }

            for(int j = 1; j <= 2 * i - 1; j++) {
                cout << ">";
            }cout << "\n";
        } 
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if(i % 2 == 0) {
            for(int k = n; k > i; k--) {
                cout << " ";
            }

            for(int j = 1; j <= 2 * i - 1; j++) {
                cout << "<";
            }cout << "\n";
        }
        else {
            for(int k = n; k > i; k--) {
                cout << " ";
            }

            for(int j = 1; j <= 2 * i - 1; j++) {
                cout << ">";
            }cout << "\n";
        } 
    }
   
    

    return 0;
}