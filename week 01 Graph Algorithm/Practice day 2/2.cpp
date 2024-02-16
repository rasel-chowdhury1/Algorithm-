#include <bits/stdc++.h>
using namespace std;
int main()
{

    /*
    Calculate time and space complexity of the following code:

    Time Complexity: O(n^2)
    Space Complexity: O(1)

    */
    int N, i, j;
    cin >> N;

    int a = 0;
    for (i = 0; i < N; i++)
    {
        cout << "i -> " << i << "| ";
        for (j = N; j > i; j--)
        {
            cout << " j -> " << j << "| ";
            a = a + i + j;
            cout << " a -> " << a;
        }
        cout << "\n";
    }

    return 0;
}
