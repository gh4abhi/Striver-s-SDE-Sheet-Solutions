// Problem Link - https://leetcode.com/problems/validate-binary-search-tree/submissions/

#define ll long long

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool DFS(TreeNode* root, ll mini, ll maxi)
    {
        if(root==nullptr)
            return 1;
        if(root->val<=mini or root->val>=maxi)
            return 0;
        return DFS(root->left,mini,root->val) and DFS(root->right,root->val,maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        return DFS(root,LONG_MIN,LONG_MAX);
    }
};