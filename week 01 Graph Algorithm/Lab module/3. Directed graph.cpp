/*
Graph Representation:
=====================


Topic: Directed Graph: Linked list / C++ vector


0 ---- 1
      / \
     2---3


0 -> 1
1 -> 2
3 -> 2
3 -> 1


Time Complexity: for worst case -> O(n^2)
                 for best case -> O(E)
Space Complexity: for worst case -> O(n^2)
                 for best case -> O(E)

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int nodes = 4;
    vector<int> adj_list[nodes];

    
    adj_list[0] = {1};
    adj_list[1] = {2};
    adj_list[2] = {};
    adj_list[3] = {1, 2};

    for (int i = 0; i < nodes; i++) 
    {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
