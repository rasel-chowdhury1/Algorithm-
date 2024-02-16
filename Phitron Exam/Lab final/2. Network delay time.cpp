// Problem link: https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(vector<vector<int>> &times, int n, int src)
    {
        vector<pair<int, int>> adj_list[101];
        vector<int> Distance(101, 1e4);
        Distance[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : times)
        {
            adj_list[it[0]].push_back({it[1], it[2]});
        }

        pq.push({0, src});
        int ans = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int node = it.second;

            for (auto i : adj_list[node])
            {
                if (dis + i.second < Distance[i.first])
                {
                    Distance[i.first] = dis + i.second;
                    pq.push({dis + i.second, i.first});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (Distance[i] == 1e4)
                return -1;
            ans = max(ans, Distance[i]);
        }

        return ans;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        return dijkstra(times, n, k);
    }
};