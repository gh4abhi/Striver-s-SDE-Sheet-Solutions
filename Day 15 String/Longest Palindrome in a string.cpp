// Problem Link - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution {
  public:
    
    ll expand(ll start, ll end, string &s)
    {
        while(start>=0 and end<s.length() and s[start]==s[end])
            start--, end++;
        return (end-start-1);
    }
  
    string longestPalin (string S) {
        ll start = 0, end = 0;
        ll len = 0;
        for(ll i=0;i<S.length();i++)
        {
            ll op = max(expand(i,i,S),expand(i,i+1,S));
            if(op>len)
            {
                len = op;
                start = i-(len-1)/2;
                end = i+(len)/2;
            }
        }
        return S.substr(start,end-start+1);
    }
};