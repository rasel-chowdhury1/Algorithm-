#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) arr.push_back(nums[i]);
        for (int i = 0; i < arr.size(); i++) nums.push_back(arr[i]);
        return nums;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    vector<int> ans = s.getConcatenation(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}