// Problem Link - https://www.codingninjas.com/codestudio/problems/975497?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
ll DFS(BinaryTreeNode<int>* root)
{
    if(root==nullptr)
        return 0;
    ll lef = DFS(root->left);
    ll rig = DFS(root->right);
    if(lef==-1 or rig==-1 or abs(lef-rig)>1)
        return -1;
    return 1+max(lef,rig);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    ll ans = DFS(root);
    if(ans==-1)
        return 0;
    return 1;
}