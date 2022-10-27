// Problem Link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

int minSumPath(vector<vector<int>> &grid) {
    ll m = grid.size();
    ll n = grid[0].size();
    vector<vector<ll>> dp(m,vector<ll>(n,-1));
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i==0 and j==0)
                dp[i][j] = grid[i][j];
            else 
            {
                ll up = INT_MAX;
                ll left = INT_MAX;
                if(i-1>=0)
                    up = dp[i-1][j];
                if(j-1>=0)
                    left = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(left,up);
            }
        }
    }
    return dp[m-1][n-1];
}