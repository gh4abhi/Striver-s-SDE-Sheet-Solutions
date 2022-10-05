// Problem Link - https://www.codingninjas.com/codestudio/problems/920464?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
#define ll int

/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void DFS(BinaryTreeNode<int> *root, ll x, ll & ans)
{
    if(root==nullptr)
        return;
    if(root->data==x)
    {
        ans = x;
        return;
    }
    if(root->data<x)
        DFS(root->right,x,ans);
    else
    {
        ans = root->data;
        DFS(root->left,x,ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    ll ans = -1;
    DFS(node,x,ans);
    return ans;
}