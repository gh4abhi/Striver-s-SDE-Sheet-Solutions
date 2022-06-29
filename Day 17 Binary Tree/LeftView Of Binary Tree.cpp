// Problem Link - https://www.codingninjas.com/codestudio/problems/left-view-of-a-binary-tree_920519?topList=striver-sde-sheet-problems&leftPanelTab=1

#define ll int

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
ll row;
void leftView(TreeNode<ll>* root,ll r, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    if(r>row)
        row = r, ans.push_back(root->data);
    leftView(root->left, r+1,ans);
    leftView(root->right, r+1,ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<ll> ans;
    row = 0;
    if(root)
        ans.push_back(root->data);
    leftView(root,0,ans);
    return ans;
}