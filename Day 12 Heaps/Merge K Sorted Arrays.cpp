// Problem Link - https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h>
#define ll int

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k)
{
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    vector<ll> ans;
    ll m = arr.size();
    for(ll i=0;i<m;i++)
        pq.push({arr[i][0],{i,0}});
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        ans.push_back(cur.first);
        ll i = cur.second.first;
        ll j = cur.second.second;
        if(j+1<arr[i].size())
            pq.push({arr[i][j+1],{i,j+1}});
    }
    return ans;
}
