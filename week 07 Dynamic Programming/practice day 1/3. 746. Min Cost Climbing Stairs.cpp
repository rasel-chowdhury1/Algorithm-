#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {10, 15, 20};
    cout << s.minCostClimbingStairs(arr);
    return 0;
}