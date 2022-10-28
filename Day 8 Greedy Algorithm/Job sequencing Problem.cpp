// Problem Link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

#define ll int

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(struct Job &a, struct Job &b)
    {
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        ll profit= 0;
        ll maxi = INT_MIN;
        for(ll i=0;i<n;i++)
            maxi = max(maxi,arr[i].dead);
        vector<ll> vis(maxi+1,0);
        ll count = 0;
        for(ll i=0;i<n;i++)
        {
            ll op = arr[i].dead;
            while(op>0 and vis[op]==1)
                op-=1;
            if(op>0)
                vis[op] = 1, profit+=arr[i].profit, count+=1;
        }
        return {count,profit};
    } 
};