// Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

#define ll int

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<ll> m(256,-1);
        ll start = 0, ans = 0;
        if(s.length()==0)
            return 0;
        for(ll i=0; i<s.length(); i++)
        {
            if(m[s[i]]==-1 or m[s[i]]<start)
                ans = max(ans, i-start+1);
            else
                start = m[s[i]] + 1;
            m[s[i]] = i;
        }
        return ans;
    }
};