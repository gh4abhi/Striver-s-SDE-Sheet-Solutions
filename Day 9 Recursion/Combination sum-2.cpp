// Problem Link - https://leetcode.com/problems/combination-sum-ii/

#define ll int

class Solution {
public:
    
    void DFS(ll ind, vector<vector<ll>> &ans, vector<ll> &ds, vector<ll> &arr, ll target)
    {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(ll i=ind;i<arr.size();i++)
        {
            if(i>ind and arr[i]==arr[i-1])
                continue;
            ds.push_back(arr[i]);
            DFS(i+1,ans,ds,arr,target-arr[i]);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<ll>> ans;
        vector<ll> ds;
        sort(arr.begin(),arr.end());
        DFS(0,ans,ds,arr,target);
        return ans;
    }
};