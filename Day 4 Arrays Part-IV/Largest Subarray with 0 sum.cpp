// Problem Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#define ll int

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<ll,ll> m;
        ll sum = 0;
        ll ans = 0;
        for(ll i=0;i<A.size();i++)
        {
            sum += A[i];
            if(sum==0)
                ans = max(ans,i+1);
            else if(m.count(sum)==0)
                m[sum] = i;
            else
                ans = max(ans,i-m[sum]);
        }
        return ans;
    }
};