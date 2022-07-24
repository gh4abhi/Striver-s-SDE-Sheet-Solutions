// Problem Link - https://www.codingninjas.com/codestudio/problems/920552?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

ll DFS(TreeNode<int> *root, ll& ans)
{
    if(root==nullptr)
        return 0;
    ll lef = DFS(root->left,ans);
    ll rig = DFS(root->right,ans);
    ans = max(ans,lef+rig);
    return 1 + max(lef,rig);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    ll ans = -1e18;
    DFS(root,ans);
    return ans;
}
