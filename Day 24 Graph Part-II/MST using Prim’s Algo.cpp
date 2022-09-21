// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// O(N^2) Approach

/*#define ll int

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<ll> key(n,INT_MAX);
        vector<ll> mstSet(n,0);
        vector<ll> par(n,-1);
        key[0] = 0;
        par[0] = -1;
        for(ll count = 0; count<n-1;count++)
        {
            ll mini = INT_MAX;
            ll u;
            for(ll i=0;i<n;i++)
                if(key[i]<mini and mstSet[i]==0)
                    mini = key[i], u = i;
            mstSet[u] = 1;
            for(auto i:adj[u])
            {
                ll v = i[0];
                ll w = i[1];
                if(mstSet[v]==0 and w<key[v])
                    par[v] = u, key[v] = w;
            }
        }
        ll sum = 0;
        for(auto i:key)
            sum += i;
        return sum;
    }
};*/

// O(N + E) + O(NlogN) => O(NlogN) Approach

#define ll int

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<ll> key(n,INT_MAX);
        vector<ll> mstSet(n,0);
        vector<ll> par(n,-1);
        key[0] = 0;
        par[0] = -1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        while(pq.size())
        {
            ll u = pq.top().second;
            pq.pop();
            mstSet[u] = 1;
            for(auto i:adj[u])
            {
                ll v = i[0];
                ll w = i[1];
                if(mstSet[v]==0 and w<key[v])
                    par[v] = u, key[v] = w, pq.push({key[v],v});
            }
        }
        ll sum = 0;
        for(auto i:key)
            sum += i;
        return sum;
    }
};
