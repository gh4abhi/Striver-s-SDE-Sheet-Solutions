// Problem Link - https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

vector<ll> prefixFunction(string &p)
{
    ll m = p.length();
    vector<ll> prefix(m,0);
    prefix[0] = 0;
    for(ll i=1;i<m;i++)
    {
        ll j = prefix[i-1];
        while(j>0 and p[i]!=p[j])
            j = prefix[j-1];
        if(p[i]==p[j])
            j++;
        prefix[i] = j;
    }
    return prefix;
}

int minCharsforPalindrome(string str) {
    string op = str;
    reverse(op.begin(),op.end());
    string p = str + "$" + op;
    vector<ll> prefix = prefixFunction(p);
    return str.length()-prefix[p.length()-1];
}
