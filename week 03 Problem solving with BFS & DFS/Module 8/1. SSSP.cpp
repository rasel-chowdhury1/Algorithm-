/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69

 test case:
 7 8
 1 2
 1 3
 2 4
 3 4
 3 6
 4 6
 6 7
 6 5
*/
//SSSP -> Single Source Shortest Path

#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vll vector<ll>
#define endl "\n"
using namespace std;

const ll maxN = 1e5;
vector<ll>adj_list[maxN];
ll visited[maxN];
ll level[maxN];

/*
Time complexity: O(N + E) 
Space complexity: O(N + E) 
*/

void bfs(ll src)
{
    queue<ll>q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);
    while (!q.empty()) //O(n)
    {
        ll head = q.front();
        q.pop();
        for(auto adj_node: adj_list[head]){ //O(2E)
            if(visited[adj_node]==0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    fast;
    ll n, e;
    cin >> n >> e;
    for (ll i = 1; i <= e; i++) //O(e)
    {
        ll u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    ll source = 1;
    bfs(source);

    for(ll i = 1; i <= n; i++) //O(n)
        cout<<"Vertex(node): "<<i<<" -> "<<level[i]<<endl;

    return 0;
}