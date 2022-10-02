// Problem Link - https://www.codingninjas.com/codestudio/problems/630459?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
#define ll int

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<ll> temp;
    temp.push_back(arr[0]);
    for(ll i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
            temp.push_back(arr[i]);
        else
        {
            ll ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
