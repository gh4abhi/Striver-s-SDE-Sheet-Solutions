// Problem Link - https://www.codingninjas.com/codestudio/problems/630420?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
#define ll long long

int editDistance(string str1, string str2)
{
    ll m = str1.length(), n = str2.length();
    vector<ll> dp(n+1,0);
    for(ll j=0;j<n+1;j++)
        dp[j] = j;
    vector<ll> temp;
    for(ll i=1;i<m+1;i++)
    {
        temp = dp;
        dp[0] = i;
        for(ll j=1;j<n+1;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[j] = temp[j-1];
            else
                dp[j] = 1 + min({temp[j],temp[j-1],dp[j-1]});
        }
    }
    return dp[n];
}