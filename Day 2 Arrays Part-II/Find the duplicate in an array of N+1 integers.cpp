// Problem Link - https://leetcode.com/problems/find-the-duplicate-number/

#define ll int

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                return abs(nums[i]);
            nums[abs(nums[i])-1] *= (-1);
        }
        return -1;
    }
};