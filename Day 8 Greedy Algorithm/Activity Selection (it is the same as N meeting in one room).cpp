// Problem Link - https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
#define ll int

bool cmp(pair<ll,ll> &a, pair<ll,ll> &b)
{
    if(a.second!=b.second)
        return a.second<b.second;
    return a.first<b.first;
}

int maximumActivities(vector<int> &start, vector<int> &end) {
    ll n = start.size();
    vector<pair<ll,ll>> meet(n);
    for(ll i=0;i<n;i++)
        meet[i] = {start[i],end[i]};
    sort(meet.begin(),meet.end(),cmp);
    ll maxi = INT_MIN;
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        if(meet[i].first>=maxi)
            maxi = meet[i].second, ans++;
    }
    return ans;
}