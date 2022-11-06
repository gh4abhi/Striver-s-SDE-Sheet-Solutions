// Problem Link - https://leetcode.com/problems/subsets-ii/

#define ll int

class Solution {
public:
    void DFS(ll ind, vector<ll>& nums, vector<vector<ll>> &ans, vector<ll> &ds)
    {
        ans.push_back(ds);
        for(ll i=ind;i<nums.size();i++)
        {
            if(i>ind and nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            DFS(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<ll>> ans;
        vector<ll> ds;
        DFS(0,nums,ans,ds);
        return ans;
    }
};