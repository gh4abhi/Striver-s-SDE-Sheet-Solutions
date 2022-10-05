// Problem Link - https://www.codingninjas.com/codestudio/problems/920457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#define ll int

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    ll ans = -1;
    TreeNode<int> * cur = root;
    while(cur)
    {
        if(cur->val<=x)
            ans = cur->val, cur = cur->right;
        else
            cur = cur->left;
    }
    return ans;
}