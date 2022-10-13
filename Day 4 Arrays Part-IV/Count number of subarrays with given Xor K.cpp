// Problem Link - https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    int xr = -1;
    int ans = 0;
    for(auto i:A)
    {
        if(xr==-1)
            xr = i;
        else
            xr = xr^i;
        if(xr==B)
            ans++;
        if(m.count(xr^B))
            ans += m[xr^B];
        m[xr]++;
    }
    return ans;
}
