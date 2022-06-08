// Problem Link - https://www.codingninjas.com/codestudio/problems/majority-element_842495?topList=striver-sde-sheet-problems&leftPanelTab=0

#define ll int

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    ll count = 0;
    ll val;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]==val)
            count++;
        else if(count==0)
            val = arr[i];
        else
            count--;
    }
    count = 0;
    for(ll i=0;i<n;i++)
        if(arr[i]==val)
            count++;
    if(count>n/2)
        return val;
    return -1;
}