// Problem Link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        ll c = 0;
        for(ll i=1;i<n;i++)
            if(M[c][i]==1)
                c = i;
        for(ll i=0;i<n;i++)
            if(i!=c and (M[c][i]==1 or M[i][c]==0))
                return -1;
        return c;
    }
};