/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode* root , TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exists(root->left,target) || exists(root->right,target) ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(exists(root->left,p) && exists(root->right,q)) return root;
        else if(exists(root->left,q) && exists(root->right,p)) return root;
        else if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};