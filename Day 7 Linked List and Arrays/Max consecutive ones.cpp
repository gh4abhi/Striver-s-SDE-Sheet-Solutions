// Problem Link - https://leetcode.com/problems/max-consecutive-ones/

#define ll int
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ll ans = 0;
        ll cur = 0;
        for(auto i:nums)
        {
            if(i==1)
                cur++;
            else
                cur = 0;
            ans = max(cur,ans);
        }
        return ans;
    }
};