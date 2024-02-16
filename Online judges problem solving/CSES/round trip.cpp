/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

const int N = 2e5;
vector<int> adj_list[N];
int visited[N], parent[N];
int start, endd;

bool detect_cycle(int src)
{
    visited[src] = 1;

    for(auto adj_node: adj_list[src])
    {
        if(adj_node == parent[src])continue;
        if(visited[adj_node]==0){
            parent[adj_node]=src;
            bool ok = detect_cycle(adj_node);
            if(ok)return true;
        }
        if(visited[adj_node]==1){
            start = src;
            endd = adj_node;
            return true;
        }
    }
    visited[src] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=m ; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if(visited[i]==0)
        {
            bool ok = detect_cycle(i);
            if(ok){cycle = true;break;}
        }
    }

    if(cycle){
        vector<int>cities;
        int temp = start;
        cities.push_back(temp);
        while (temp!=endd)
        {
            cities.push_back(parent[temp]);
            temp = parent[temp];
        }

        cities.push_back(start);
        cout<<cities.size()<<endl;
        for(auto city: cities)cout<<city<<" ";
        
    }else cout<<"IMPOSSIBLE"<<endl;
    

    return 0;
}