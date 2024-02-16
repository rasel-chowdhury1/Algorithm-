/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;


// bool dfs(vector<vector<int>>& adj_list, vector<bool> &visited, int x, int y, int step)
// {
//     visited[x] = true;
//     visited[y] = true;

//     for(int childx: adj_list[x])
//     {
//         if(!visited[childx])
//         {
//             dfs(adj_list, visited, childx, y, step + 1);
//         }
//     }
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, e;
    cin >> n >> e;

    vector<vector<int>>adj_list(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int x, y, k;
    cin >> x >> y >> k;

    vector<bool>visited(n, false);




    
    return 0;
}