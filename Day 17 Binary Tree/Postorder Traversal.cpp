// Problem Link - https://www.codingninjas.com/codestudio/problems/postorder-traversal_3839614?topList=striver-sde-sheet-problems

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
void postorder(TreeNode* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<ll> ans;
    postorder(root,ans);
    return ans;
}