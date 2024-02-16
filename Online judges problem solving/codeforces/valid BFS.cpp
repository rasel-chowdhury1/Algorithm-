//Failed in test case 4: didn't accepted

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxN = 100;
ll visited[maxN];
vector<ll> adj[maxN];
vector<ll> ans;
 
void bfs(ll node)
{
    queue<ll> q;
    visited[node] = 1;
    q.push(node);
 
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
 
        ans.push_back(head);
        for (auto child : adj[head])
        {
            if (visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
            }
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    bfs(1);
    int found = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == ans[i])
            found = 1;
        else
            found = 0;
    }
 
    if(found)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}