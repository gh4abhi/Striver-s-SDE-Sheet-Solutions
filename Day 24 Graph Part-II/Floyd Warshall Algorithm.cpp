// Problem Link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#define ll int

class Solution {
  public:
    void shortest_distance(vector<vector<int>>&matrix){
        ll n = matrix.size();
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
                if(matrix[i][j]==-1)
                    matrix[i][j] = 1e9;
        for(ll k=0;k<n;k++)
            for(ll i=0;i<n;i++)
                for(ll j=0;j<n;j++)
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
                if(matrix[i][j]==1e9)
                    matrix[i][j] = -1;
    }
};