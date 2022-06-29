// Problem Link - https://www.codingninjas.com/codestudio/problems/tree-traversal_981269?topList=striver-sde-sheet-problems&leftPanelTab=0

#define ll int

/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void preorder(BinaryTreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
void postorder(BinaryTreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
void inorder(BinaryTreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<ll> pre,pos,in;
    inorder(root,in);
    preorder(root,pre);
    postorder(root,pos);
    vector<vector<ll>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}