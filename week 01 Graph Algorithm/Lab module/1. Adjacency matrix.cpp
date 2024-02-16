/*
Graph Representation:
=====================


Topic: Adjacency Matrix: 2D array


0 ---- 1
      / \
     2---3

#total nodes = 4
#total edge = 4
#undirected + unweighted

matrix -> number of nodes x number of nodes
       -> 4x4

matrix[i][j] = 1,
    if and only if i can go to j in one directed line (i->j)

0 -> 1
1 -> 0
1 -> 2
2 -> 1
2 -> 3
3 -> 2
3 -> 1
1 -> 3


0 1 0 0
1 0 1 1
0 1 0 1
0 1 1 0

Time Complexity: for worst case -> O(n^2)
                for best case -> O(n^2)
Space Complexity: for worst case -> O(n^2)
                 for best case -> O(n^2)

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes = 4;            // O(1)
    int matrix[nodes][nodes]; // O(n^2) space

    for (int i = 0; i < nodes; i++) // O(n^2)
    {
        for (int j = 0; j < nodes; j++)
        {
            matrix[i][j] = 0;
        }
    }

    matrix[0][1] = 1; // O(E*2) -> O(E) -> worst case: O(n^2)
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    matrix[3][1] = 1;
    matrix[1][3] = 1;

    for (int i = 0; i < nodes; i++) // O(n^2)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
