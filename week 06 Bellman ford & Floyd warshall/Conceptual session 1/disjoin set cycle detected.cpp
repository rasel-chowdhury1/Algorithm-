#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edgeList;
vector<int> parent;

int find_parent(int x)
{
    if(parent[x] == -1)return x;
    return find_parent(parent[x]);
}

void union_operation(int a, int b)
{
    int parentA = find_parent(a);
    int parentB = find_parent(b);
    parent[parentA] = parentB;
}

int main()
{
    int n, e;
    cin >> n >> e;

    parent.resize(n, -1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }
    bool cycle = false;

    for (int i = 0; i < (int)edgeList.size(); i++)
    {
        pair<int, int> pr = edgeList[i];
        int a = pr.first;
        int b = pr.second; 

        int parentA = find_parent(a);
        int parentB = find_parent(b);

        if(parentA == parentB)
        {
            cycle = true;
            break;
        }
        else{
            union_operation(a, b);
        }
    }

    if(cycle) cout<<"YES\n";
    else cout<<"NO\n";
}