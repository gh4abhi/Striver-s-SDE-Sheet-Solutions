// Problem Link - https://www.codingninjas.com/codestudio/problems/1058184?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
int largestRectangle(vector < int > & heights) {
    stack<ll> st;
    ll n = heights.size();
    vector<ll> left(n);
    for(ll i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            left[i] = 0;
            st.push(i);
            continue;
        }
        while(st.size() and heights[st.top()]>=heights[i])
            st.pop();
        if(st.size()==0)
            left[i] = 0;
        else
            left[i] = st.top()+1;
        st.push(i);
    }
    while(st.size())
        st.pop();
    vector<ll> right(n);
    for(ll i=n-1;i>=0;i--)
    {
        if(st.size()==0)
        {
            right[i] = n-1;
            st.push(i);
            continue;
        }
        while(st.size() and heights[st.top()]>=heights[i])
            st.pop();
        if(st.size()==0)
            right[i] = n-1;
        else
            right[i] = st.top()-1;
        st.push(i);
    }
    ll ans = -1e18;
    for(ll i=0;i<n;i++)
        ans = max((right[i]-left[i]+1)*heights[i],ans);
    return ans;
}