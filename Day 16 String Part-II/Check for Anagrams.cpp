// Problem Link - https://leetcode.com/problems/valid-anagram/

#define ll int

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,ll> m1,m2;
        for(auto i:s)
            m1[i]++;
        for(auto i:t)
            m2[i]++;
        return m1==m2;
    }
};