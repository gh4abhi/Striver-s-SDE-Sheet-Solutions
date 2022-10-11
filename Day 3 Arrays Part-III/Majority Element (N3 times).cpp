// Problem Link - https://leetcode.com/problems/majority-element-ii/

#define ll int

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ll a = -1, b = -1;
        ll count1 = 0, count2 = 0;
        for(auto i:nums)
        {
            if(i==a)
                count1++;
            else if(i==b)
                count2++;
            else if(count1==0)
                a = i, count1 = 1;
            else if(count2==0)
                b = i, count2 = 1;
            else
                count1--, count2--;
        }
        count1=0;
        count2=0;
        for(auto i:nums)
        {
            if(i==a)
                count1++;
            else if(i==b)
                count2++;
        }
        vector<ll> ans;
        if(count1>nums.size()/3)
            ans.push_back(a);
        if(count2>nums.size()/3)
            ans.push_back(b);
        return ans;
    }
};