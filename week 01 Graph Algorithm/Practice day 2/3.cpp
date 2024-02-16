#include <bits/stdc++.h>
using namespace std;
int main()
{

    /*
    Calculate time and space complexity of the following code:

    Time Complexity: O(logn)
    Space Complexity: O(logn)

    */
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int a = 0, i = N;
        vector<int> vec;
        while (i > 0)
        {
            a += i;
            i /= 2;
            vec.push_back(a);
        }

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
