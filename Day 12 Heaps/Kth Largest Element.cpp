// Problem Link - https://leetcode.com/problems/kth-largest-element-in-an-array/

#define ll int

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<nums.size();i++)
        {
            if(i<=k-1)
                pq.push(nums[i]);
            else if(pq.top()<nums[i])
                pq.pop(), pq.push(nums[i]);
        }
        return pq.top();
    }
};