// Problem Link - https://leetcode.com/problems/is-graph-bipartite/

#define ll int

class Solution {
public:
    
    bool BFS(ll start, vector<vector<ll>> &adj, vector<ll> &color)
    {
        color[start] = 1;
        queue<ll> q;
        q.push(start);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(auto i:adj[cur])
            {
                if(color[i]==-1)
                {
                    color[i] = 1-color[cur];
                    q.push(i);
                }
                else
                    if(color[i]==color[cur])
                        return false;
            }
        }
        return true;
    }
        
    bool isBipartite(vector<vector<int>>& adj) {
        vector<ll> color(adj.size(),-1);
        for(ll i=0;i<adj.size();i++)
            if(color[i]==-1)
                if(!BFS(i,adj,color))
                    return false;
        return true;
    }
};