// Problem Link - https://www.codingninjas.com/codestudio/problems/630426?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool DFS(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(root1 and !root2)
        return false;
    if(!root1 and root2)
        return false;
    if(!root1 and !root2)
        return true;
    if(root1->data!=root2->data)
        return false;
    return DFS(root1->left,root2->right) and DFS(root1->right,root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==nullptr)
        return true;
    return DFS(root->left,root->right);
}