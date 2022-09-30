// Problem Link - https://www.codingninjas.com/codestudio/problems/1115738?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007


vector<int> stringMatch(string &str, string &pat) {
    ll d = 26;
    ll p = MOD;
    ll hashPat = 0;
    ll hashStr = 0;
    for(ll i=0;i<pat.length();i++)
    {
        hashPat *=d;
        hashPat += (pat[i]-'A' + 1)%p;
    }
    ll start = 0, end = 0;
    vector<int> ans;
    while(end<str.length())
    {
        hashStr *= d;
        hashStr += (str[end]-'A'+1)%p;
        if(end-start+1==pat.length())
        {
            if(hashStr==hashPat)
            {
                ll flag =1;
                for(ll k=0;k<pat.length();k++)
                    if(pat[k]!=str[start+k])
                        flag=0;
                if(flag)
                    ans.push_back(start);
            }
            hashStr -= (((str[start] -'A'+1))*pow(d,end-start));
            start++;
        }
        end++;
    }
    return ans;
}
