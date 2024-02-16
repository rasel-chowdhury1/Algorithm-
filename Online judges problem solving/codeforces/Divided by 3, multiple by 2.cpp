#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, bool> visited;
map<ll, vector<ll>> adj;
int n;
vector<ll> ans;
bool found = false;

void bfs(ll s)
{
    queue<ll> q;
    visited[s] = true;
    q.push(s);
    ans.push_back(s);

    while (!q.empty())
    {
        if (ans.size() == n)
        {
            found = true;
            return;
        }

        ll parent = q.front();
        q.pop();
        for (ll child : adj[parent])
        {
            if ((parent * 2) == child && !visited[child])
            {
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
                break;
            }
            else if ((parent % 3 == 0) && (parent / 3) == child && !visited[child])
            {
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
                break;
            }
        }
    }
}

void init()
{
    ans.clear();
    visited.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                adj[v[i]].push_back(v[j]);
            }
        }
    }

    // for (auto val : adj)
    // {
    //     cout << val.first << " -> ";
    //     for (auto value : val.second)
    //     {
    //         cout << value << " ";
    //     }
    //     cout << "\n";
    // }

    for (auto val : adj)
    {
        bfs(val.first);
        if (found)
        {
            break;
        }
        init();
    }

    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}