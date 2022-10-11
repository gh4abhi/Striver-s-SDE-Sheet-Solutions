// Problem Link - https://www.codingninjas.com/codestudio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    ll gap = ceil(((m+n)*1.0)/2);
    ll size = m+n;
    while(gap!=0)
    {
        ll i=0,j=gap;  
        while(j<size){
            if(j<m and arr1[i]>arr1[j])
                swap(arr1[i],arr1[j]);
            else if(i<m and j>=m and arr1[i]>arr2[j-m])
                swap(arr1[i],arr2[j-m]);
            else if(i>=m and arr2[i-m]>arr2[j-m])
                swap(arr2[i-m],arr2[j-m]);
            i+=1;
            j+=1;
        }
        if(gap==1)
            gap = 0;
        else
            gap = ceil((gap*1.0)/2);
    }
    ll i=m, j=0;
    while(j<n)
        arr1[i++] = arr2[j++];
    return arr1;
}