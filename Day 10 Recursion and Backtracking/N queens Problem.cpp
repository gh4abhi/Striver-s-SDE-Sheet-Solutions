// Problem Link - https://leetcode.com/problems/n-queens/

#define ll int

class Solution {
public:
    
    void DFS(ll ind, ll n, vector<vector<string>> &ans, vector<string> &board, vector<ll> &left, vector<ll> &lowerDiag, vector<ll> &upperDiag)
    {
        if(ind==n)
        {
            ans.push_back(board);
            return;
        }
        for(ll i=0;i<n;i++)
        {
            if(left[i]==0 and lowerDiag[ind+i]==0 and upperDiag[n-1+ind-i]==0)
            {
                left[i] = 1;
                lowerDiag[ind+i] = 1;
                upperDiag[n-1+ind-i] = 1;
                board[i][ind] = 'Q';
                DFS(ind+1,n,ans,board,left,lowerDiag,upperDiag);
                left[i] = 0;
                lowerDiag[ind+i] = 0;
                upperDiag[n-1+ind-i] = 0;
                board[i][ind] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string str = string(n,'.');
        for(ll i=0;i<n;i++)
            board[i] = str;
        vector<ll> left(n,0);
        vector<ll> lowerDiag(2*n-1,0);
        vector<ll> upperDiag(2*n-1,0);
        vector<vector<string>> ans;
        DFS(0,n,ans,board,left,lowerDiag,upperDiag);
        return ans;
    }
};