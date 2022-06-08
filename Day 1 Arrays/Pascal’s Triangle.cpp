// Problem Link - https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580?topList=striver-sde-sheet-problems&leftPanelTab=0

#define ll long long
#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<ll>> dp(n);
    dp[0].push_back(1);
    for(ll i=1;i<n;i++)
          for(ll j=0;j<i+1;j++)
          {
              if(j!=0 and j!=i)
                  dp[i].push_back(dp[i-1][j-1]+dp[i-1][j]);
              else if(j==0)
                  dp[i].push_back(dp[i-1][j]);
              else
                  dp[i].push_back(dp[i-1][j-1]);
          }
    return dp;
}
