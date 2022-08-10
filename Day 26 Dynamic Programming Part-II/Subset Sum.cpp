// Problem Link - https://leetcode.com/problems/partition-equal-subset-sum/

#define ll long long

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ll sum = 0;
        for(auto i:nums)
            sum += i;
        if(sum%2!=0)
            return false;
        sum/=2;
        vector<ll> dp(sum+1,0);
        if(nums[0]==0)
            dp[0] = 2;
        else
            dp[0]  = 1;
        if(nums[0]<=sum and nums[0]!=0)
            dp[nums[0]] = 1;
        for(ll i=1;i<nums.size();i++)
        {
            vector<ll> temp = dp;
            for(ll j=0;j<sum+1;j++)
            {
                dp[j] = temp[j];
                if(nums[i]<=j)
                    dp[j] = dp[j] or temp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};