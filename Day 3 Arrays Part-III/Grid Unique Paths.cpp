// Problem Link - https://leetcode.com/problems/unique-paths/

#define ll int

class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1.0;
        for(ll i=1;i<=(m-1);i++)
            ans = ans*(n-1 + i)/i;
        return (ll)ans;
    }
};