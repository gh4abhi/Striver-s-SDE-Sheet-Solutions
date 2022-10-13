// Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/

#define ll int

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<ll,ll> m;
        ll ans = 0;
        for(auto i:nums)
            m[i]++;
        for(auto i:nums)
        {
            ll op = 1;
            if(m.count(i-1)==0)
                while(m.count(i+op))
                    op++;
            ans = max(ans,op);
        }
        return ans;
    }
};