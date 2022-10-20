// Problem Link - https://www.interviewbit.com/problems/maximum-sum-combinations/

#define ll int

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    sort(A.begin(),A.end(),greater<ll>());
    sort(B.begin(),B.end(),greater<ll>());
    pq.push({A[0]+B[0],{0,0}});
    vector<ll> ans;
    set<pair<ll,ll>> s;
    s.insert({0,0});
    for(ll i=0;i<C;i++)
    {
        auto cur = pq.top();
        pq.pop();
        ans.push_back(cur.first);
        if(cur.second.first+1<A.size() and s.find({cur.second.first+1,cur.second.second})==s.end())
            pq.push({A[cur.second.first+1]+B[cur.second.second],{cur.second.first+1,cur.second.second}}), s.insert({cur.second.first+1,cur.second.second});
        if(cur.second.second+1<B.size() and s.find({cur.second.first,cur.second.second+1})==s.end())
            pq.push({A[cur.second.first]+B[cur.second.second+1],{cur.second.first,cur.second.second+1}}), s.insert({cur.second.first,cur.second.second+1});
    }
    return ans;
}
