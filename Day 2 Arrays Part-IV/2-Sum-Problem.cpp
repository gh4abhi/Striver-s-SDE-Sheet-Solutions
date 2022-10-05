// Problem Link - https://leetcode.com/problems/two-sum/

#define ll int

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<ll,ll> m;
        for(ll i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i]))
                return {i,m[target-nums[i]]};
            m[nums[i]] = i;
        }
        return {};
    }
};