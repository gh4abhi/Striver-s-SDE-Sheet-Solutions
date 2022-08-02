// Problem Link - https://leetcode.com/problems/course-schedule/

#define ll int

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<ll> inDegree(numCourses,0);
        vector<vector<ll>> adj(numCourses);
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
            inDegree[i[1]]++;
        }
        queue<ll> q;
        for(ll i=0;i<numCourses;i++)
            if(inDegree[i]==0)
                q.push(i);
        ll count = 0;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            count++;
            for(auto i:adj[cur])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        return count == numCourses;
    }
};