// Problem Link - https://www.codingninjas.com/codestudio/problems/842495?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#define ll int

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    ll count = 1;
    ll op = arr[0];
    for(ll i=1;i<n;i++)
    {
        if(count==0)
            op = arr[i],count=1;
        else if(op==arr[i])
            count++;
        else
            count--;
    }
    count = 0;
    for(ll i=0;i<n;i++)
        if(arr[i]==op)
            count++;
    if(count>n/2)
        return op;
    return -1;
}