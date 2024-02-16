#include <bits/stdc++.h>
using namespace std;
int main()
{

    /*
    Calculate time and space complexity of the following code snippet:
    
    Time Complexity: O(n)
    Space Complexity: O(n^2)

    */
    int N, M, i, j;
    cin >> N >> M;

    int a = 0, b = 0;

    int matrix[N][M];

    for (i = 0; i < N; i++)
    {
        a = a + i;
        matrix[i][i] = a;
    }

    for (j = 0; j < M; j++)
    {
        b = b + 2 * j;
    }

    


    return 0;
}
