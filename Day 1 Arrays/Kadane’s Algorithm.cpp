// Problem Link - https://leetcode.com/problems/maximum-subarray/

#define ll int

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ll ans = nums[0];
        ll sum = 0;
        for(auto i:nums)
        {
            sum += i;
            ans = max(sum,ans);
            if(sum<0)
                sum = 0;
        }
        return ans;
    }
};