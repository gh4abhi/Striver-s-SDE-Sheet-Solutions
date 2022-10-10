// Problem Link - https://www.codingninjas.com/codestudio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<ll> dis(n,1e9);
    dis[src-1] = 0;
    for(ll i=0;i<n-1;i++)
        for(auto i:edges)
            if(dis[i[0]-1]!= 1e9 and dis[i[0]-1] + i[2] < dis[i[1]-1])
                dis[i[1]-1] = dis[i[0]-1] + i[2];
    return dis[dest-1];
}