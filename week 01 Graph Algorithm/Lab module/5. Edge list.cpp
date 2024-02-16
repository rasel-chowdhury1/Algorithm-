/*
Graph Representation:
=====================


Topic: Edge List: Vector/Linked list


0 ---- 1
      / \
     2---3


Only edge: [[0, 1] [1, 2] [1, 3] [2, 3]]

weighted edge: [[0, 1, 3] [1, 2, 7] [1, 3, 5] [2, 3, 9]]

Time complexity: best case-> O(E), worst case-> O(n^2)
Space complexity: best case-> O(E), worst case-> O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes = 4;
    vector<vector<int>> edge_list = {{0, 1}, {1, 2}, {1, 3}, {2, 3}};

    // edge_list.push_back({0, 1});
    // edge_list.push_back({1, 2});
    // edge_list.push_back({1, 3});
    // edge_list.push_back({2, 3});

    for (int i = 0; i < edge_list.size(); i++)
    {
        cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }

    return 0;
}
