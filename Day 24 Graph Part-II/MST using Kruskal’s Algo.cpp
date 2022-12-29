// Problem Link - https://www.codingninjas.com/codestudio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
#define ll int

ll findPar(ll u, vector<ll> &par)
{
    if(par[u]==u)
        return u;
    return par[u] = findPar(par[u],par);
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),[](vector<ll> &a, vector<ll> &b){
       return a[2]<b[2]; 
    });
    vector<ll> par(n,0), rank(n,0);
    for(ll i=0;i<n;i++)
        par[i] = i;
    ll ans = 0;
    for(auto i:graph)
    {
        ll u = i[0]-1;
        ll v = i[1]-1;
        ll w = i[2];
        ll p1 = findPar(u,par);
        ll p2 = findPar(v,par);
        if(p1!=p2)
        {
            if(rank[p1]>rank[p2])
                par[p2] = p1;
            else if(rank[p2]>rank[p1])
                par[p1] = p2;
            else
                par[p2] = p1;
            ans += w;
        }
    }
    return ans;
}