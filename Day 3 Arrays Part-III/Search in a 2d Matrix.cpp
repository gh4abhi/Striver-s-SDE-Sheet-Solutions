// Problem Link - https://leetcode.com/problems/search-a-2d-matrix/

#define ll int

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll m = matrix.size();
        ll n = matrix[0].size();
        ll start = 0, end = m*n-1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            ll op = matrix[mid/n][mid%n];
            if(op==target)
                return true;
            else if(op>target)
                end = mid-1;
            else
                start = mid+1;
        }
        return false;
    }
};