// Problem Link - https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
#define ll int
    vector<ll> ans;
    void findSum(vector<ll> &arr, ll n, ll ind, ll sum)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        findSum(arr,n,ind+1,sum+arr[ind]);
        findSum(arr,n,ind+1,sum);
    }
    

vector<int> subsetSum(vector<int> &num)
{        ans.clear();
        findSum(num,(ll)num.size(),0,0);
 sort(ans.begin(),ans.end());
        return ans;
}