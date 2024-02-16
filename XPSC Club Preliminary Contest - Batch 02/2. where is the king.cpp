#include <bits/stdc++.h>
using namespace std;

int findKingIndex(vector<int> &nums)
{
    int totalSum = 0;
    for (int num : nums)
    {
        totalSum += num;
    }

    int leftSum = 0;
    int rightSum = totalSum;

    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int Index = findKingIndex(nums);
        cout << Index << endl;
    }

    return 0;
}
