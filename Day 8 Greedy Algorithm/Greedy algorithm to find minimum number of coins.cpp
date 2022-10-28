// Problem Link - https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 

#define ll int

int findMinimumCoins(int V) 
{
        ll coins[9];
        coins[0]=1;
        coins[1] = 2;
        coins[2] = 5;
        coins[3] = 10;
        coins[4] = 20;
        coins[5] = 50;
        coins[6] = 100;
        coins[7] = 500;
        coins[8] = 1000;
        ll M = 9;
        ll ans = 0;
        for(ll i=M-1;i>=0;i--)
        {
            ll op = V/coins[i];
            ans += op;
            V -= coins[i]*op;
        }
        return ans;
}
