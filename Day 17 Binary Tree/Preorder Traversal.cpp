// Problem Link - https://www.codingninjas.com/codestudio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems

#define ll int
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preorder(TreeNode* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<ll> ans;
    preorder(root,ans);
    return ans;
}