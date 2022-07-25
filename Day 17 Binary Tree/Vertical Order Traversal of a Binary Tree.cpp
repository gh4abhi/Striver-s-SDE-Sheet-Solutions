// Problem Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#define ll int
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<ll,map<ll,multiset<ll>>> m;
    queue<pair<TreeNode *,pair<ll,ll>>> q;
    q.push({root,{0,0}});
    while(q.size())
    {
        auto p = q.front();
        ll c = p.second.first;
        ll r = p.second.second;
        TreeNode* cur = p.first;
        q.pop();
        m[c][r].insert(cur->val);
        if(cur->left)
            q.push({cur->left,{c-1,r+1}});
        if(cur->right)
            q.push({cur->right,{c+1,r+1}});
    }
    vector<vector<ll>> ans;
    for(auto i:m)
    {
        vector<ll> temp;
        for(auto j:i.second)
            temp.insert(temp.end(),j.second.begin(),j.second.end());
        ans.push_back(temp);
    }
    return ans;
    }
};