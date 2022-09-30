// Problem Link - https://www.codingninjas.com/codestudio/problems/1115738?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007


vector<int> stringMatch(string &str, string &p) {
        ll d = 26;
        ll r = 5381;
        ll hashPat = 0;
        ll hashStr = 0;
        ll n = str.length();
        ll m = p.length();
        vector<int> ans;
        for(ll i=0;i<m;i++)
            hashPat = (hashPat*d + (p[i]-'A'+1))%r;
        ll start = 0, end = 0;
        ll op = 1;
        for(ll i=0;i<m-1;i++)
            op = (op*d)%r;
        while(end<n)
        {
            if(hashStr<0)
                hashStr += r;
            hashStr = (hashStr*d + (str[end] -'A' + 1))%r;
            if(end-start+1==m)
            {
                if(hashStr==hashPat and str.substr(start,m)==p)
                    ans.push_back(start);
                hashStr = (hashStr - (str[start]-'A' + 1)*op)%r;
                start++;
            }
            end++;
        }
        return ans;
}
