// Problem Link - https://leetcode.com/problems/permutations/

#define ll int

class Solution {
public:
    
    void DFS(ll ind, vector<vector<ll>> &ans, vector<ll> &nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(ll i=ind; i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            DFS(ind+1,ans,nums);
            swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<ll>> ans;
        DFS(0,ans,nums);
        return ans;
    }
};