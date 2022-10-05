// Problem Link - https://www.codingninjas.com/codestudio/problems/920438?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
    ll ans = -1;
    void DFS(TreeNode<int>* root, ll k, ll &op)
    {
        if(root==nullptr)
            return;
        DFS(root->right,k,op);
        op+=1;
        if(op==k)
            ans = root->data;
        DFS(root->left,k,op);
    }
int KthLargestNumber(TreeNode<int>* root, int k) 
{
        ans = -1;
        ll op = 0;
        DFS(root,k,op);
        return ans;
}
