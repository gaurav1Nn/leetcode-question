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
int levels(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(levels(root->left),levels(root->right));
}

    void preorder(TreeNode* root  , int levels , vector<int>& ans){
        if(root==NULL) return ;
        ans[levels] = root->val;
        preorder(root->left,levels+1,ans);
        preorder(root->right,levels+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<int> ans(n,0);
        preorder(root,0,ans);
        return ans;
    }
};