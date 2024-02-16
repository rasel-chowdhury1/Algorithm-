/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        int pre_sum = 0, res = 0;
        for(int i = 0; i < satisfaction.size(); i++){
            pre_sum +=satisfaction[i];
            if(pre_sum < 0) break;
            res+=pre_sum;
        }
        return res;
    }
};