// Problem Link - https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr, ll *temp, ll start, ll mid, ll end)
{
    ll i,j,ans=0;
    i = start;
    j = mid+1;
    ll k = start;
    while(i<=mid and j<=end)
    {
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
        {
            ans += (mid-i+1);
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];
    for(ll ind=start;ind<=end;ind++)
        arr[ind] = temp[ind];
    return ans;
}

ll mergeSort(long long *arr, long long *temp, ll start, ll end)
{
    if(start<end)
    {
        ll ans = 0;
        ll mid = start + (end-start)/2;
        ans += mergeSort(arr,temp,start,mid);
        ans += mergeSort(arr,temp,mid+1,end);
        ans += merge(arr,temp,start,mid,end);
        return ans;
    }
    return 0;
}

long long getInversions(long long *arr, int n){
    long long* temp = new ll[n];
    return mergeSort(arr,temp,0,n-1);
}