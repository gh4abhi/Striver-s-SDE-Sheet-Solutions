// Problem Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

#define ll int

class KthLargest {
public:
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i:nums)
            add(i);
    }
    
    int add(int val) {
        if(pq.size()<k)
            pq.push(val);
        else if(val>pq.top())
            pq.pop(), pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */